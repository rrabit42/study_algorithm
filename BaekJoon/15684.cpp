// 재귀 함수 사용(완전 탐색)
 
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int Min(int A, int B) { if (A > B) return B; return A; }

/*
	N: 세로선
	M: 가로선
	H: 세로선마다 가로선을 놓을 수 있는 위치의 개수

	즉, N(세로)과 H(위치)가 교차하는 지점에 M(가로)을 놓을 수 있다.
	두 가로선이 연속하거나 접히면 X

	i번 세로선의 결과가 i번이 나오도록 추가해야하는 가로선의 개수
	ex) 1번 세로선은 1번으로, 2번 세로선은 2번으로 가게끔
*/

int n, m, h;
int a, b;
int arr[11][31] = { 0, };
int min_lad = 1000;
int num = 0;

// 사다리 타기
// 그냥 여기서 처음부터 끝까지 타는거야~
bool ladder() {

	for (int i = 1; i <= n; i++) {
		int now = i;

		for (int j = 1; j <= h; j++) {
			// 내 기준 왼쪽에 가로선이 있을 때
			if (arr[i - 1][j] == 1) i -= 1;

			// 내 기준 오른쪽에 가로선이 있을 때
			else if (arr[i][j] == 1) i += 1;
		}

		// 하나라도 틀리면 false
		if (now != i) return false;
	}

	// 모두가 각자 지점에 도달했을 때
	return true;
}

// 놓친부분! 재귀 함수 작성 요령을 기르자!!
void line(int idx, int num) {

	if (num > 3) return;

	if (ladder()) {
		min_lad = Min(min_lad, num);
		return;
	}

	// 가로로 살피기
	for (int k = idx; k <= h; k++) {
		for (int j = 1; j < n; j++) { // arr[n]에서 그으면 범위 초과
			// 이미 그어져 있으면 pass, 서로 접하면 안되므로 pass
			if ((arr[j][k] == 1) || (arr[j - 1][k] == 1) || (arr[j + 1][k] == 1))
				continue;

			arr[j][k] = 1; // 놓친부분! 여기다 그을 거라서 [j+1][k]도 안됨!
			line(k, num + 1); // 놓친부분! num을 여기 놔야 사다리 뺄 때 num -1 해줄필요X
			/*
				num +=1;
				line(k);
				num -=1;
				도 가능!
			*/
			arr[j][k] = 0;
		}
	}
}

// 놓을 수 있는 모든 가로선에 다 놓아보면서 최소값을 갱신해 나가는 완전 탐색 문제
int main() {

	cin >> n >> m >> h;
	
	// 가로선 정보
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		arr[b][a] = 1;	// 놓친부분! (b,a) - (b+1,a) 가로선 연결
	}

	// 출발
	// arr[i][0]에서 출발해서 arr[i][h-1]에 도착해야함
	line(1,0);

	if (min_lad == 1000) min_lad = -1;

	cout << min_lad << endl;

	return 0;
}


// dfs, 백트래킹 방식
/*
 #include <iostream>
 using namespace std;
 #define N_MAX 10 + 5 
 #define H_MAX 30 + 5 
 #pragma warning(disable:4996)
 // global
 int ladder_map[H_MAX][N_MAX] = { 0 };
 int N, M, H;

 // 정답이 되는지 출력
 int is_answer() {
     for (int col = 1; col <= N; col++) {
         int now_col = col;
         for (int row = 1; row <= H; row++) {
             int left = ladder_map[row][now_col - 1];
             int right = ladder_map[row][now_col];

             if (left)  now_col--;
             if (right) now_col++;
         }
         if (now_col != col) return 0;
     }
     return 1;
 }

 // 사다리를 놓는다. dfs 방식으로 설치하고 완료되면 종료
 int make_ladder(int _end_depth, int _now_depth, int _row, int _col) {
     if (_now_depth == _end_depth) {
         if (is_answer()){
             printf("%d", _now_depth);
             exit(0);
         }
         return 0;
     }
     int row = _col + 1 > H ? _row + 1 : _row;
     int col = _col + 1 > H ? 0 : _col + 1;
     for (; row <= H; row++) {
         for (; col <= N; col++) {
             if (ladder_map[row][col - 1] || ladder_map[row][col] || ladder_map[row][col + 1]) continue;
             ladder_map[row][col] = 1;
             make_ladder(_end_depth, _now_depth + 1, row, col);
             ladder_map[row][col] = 0;
         }
         col = 1;
     }
     return 0;
 }

 int main() {
     scanf("%d %d %d", &N, &M, &H);
     for (int m_idx = 0; m_idx < M; m_idx++) {
         int a, b; scanf("%d %d", &a, &b);
         ladder_map[a][b] = 1;
     }
     if (is_answer()) {
         printf("0"); return 0;
     }
     for (int plus = 1; plus <= 3; plus++) {
         for (int row = 1; row <= H; row++) {
             for (int col = 1; col <= N; col++) {
                 if (ladder_map[row][col - 1] || ladder_map[row][col] || ladder_map[row][col + 1]) continue;
                 ladder_map[row][col] = 1;
                 make_ladder(plus, 1, row, col);
                 ladder_map[row][col] = 0;
             }
         }
     }
     printf("-1"); return 0;
 }
*/
