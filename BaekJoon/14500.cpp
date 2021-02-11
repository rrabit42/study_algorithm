// ㅜ 도형을 제외하고는 모두 depth(level) = 3이다. -> dfs 가능
// ㅜ 도형은 시작점을 어떻게 잡더라도 절대로 depth가 3에서 끝날 수가 없어서
// ㅗ/ㅜ/ㅏ/ㅓ 이 4가지 모양에 대해 범위를 파악하면서 모든 정점에서 계산 해줘야함

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 500

using namespace std;

int n, m, answer;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dxy[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

// 알아서 depth가 3인 모형들이 만들어지는 것!(와우...)
// 당연히 회전, 대칭 알아서 다 됨...
void dfs(int x, int y, int sum, int cnt) {
	visited[x][y] = true;

	// depth가 3이면(0,1,2,3) return 해주면 되니까
	if (cnt == 3) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dxy[i][0];
		int ny = y + dxy[i][1];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny] == true) continue;

		// 한 칸 선택하고 다시 거기서 4방향 또 선택(갔었던 곳 빼고)
		dfs(nx, ny, sum + map[nx][ny], cnt + 1);
		visited[nx][ny] = false;
	}
}

// dfs로 만들 수 없는 ㅜ 모형은 따로 해주기
void shape(int x, int y) {

	// ㅗ(현재 좌표는 ㅡ의 가운데)
	if (x - 1 >= 0 && x + 1 < n && y + 1 < m) {
		answer = max(answer, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1]);
	}

	// ㅏ(현재 좌표는 ㅣ의 가운데)
	if (x + 1 < n && y + 1 < m && y - 1 >= 0) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x + 1][y] + map[x][y - 1]);
	}

	// ㅜ(현재 좌표는 ㅡ의 가운데)
	if (x - 1 >= 0 && x + 1 < n && y - 1 >= 0) {
		answer = max(answer, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1]);
	}

	// ㅓ(현재 좌표는 ㅣ의 가운데)
	if (y + 2 < m && x - 1 >= 0) {
		answer = max(answer, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1]);
	}
}

void Shape2(int x, int y) {
	int tmp_sum = 0;

}

int main() {
	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 시작점은 계속 달라지고, visited도 초기화
			memset(visited, false, sizeof(visited));
			dfs(i, j, map[i][j], 0);
			shape(i, j);
		}
	}

	// 출력
	cout << answer << '\n';
}



/*
dfs를 어떻게 돌려야할지 감을 못잡겠음.
각 도형마다 좌표 범위가 다르기 때문..ㅠㅠ

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define MAX 500

using namespace std;

int n, m;
long numbers[MAX][MAX];
long score, sum;

// 테트로미노
int t1[4][2] = { {0,0}, {1,0}, {2,0}, {3,0} }; // ㅡ :맨 왼쪽이 기준
int t2[4][2] = { {0,0}, {1,0}, {0,1}, {1,1} }; // ㅁ :왼쪽 아래가 기준
int t3[4][2] = { {0,0}, {1,0}, {0,1}, {0,2} }; // L : 왼쪽 아래가 기준
int t4[4][2] = { {0,0}, {0,1}, {-1,1}, {-1,2} }; // ㄴㄱ: 맨 아래가 기준
int t5[4][2] = { {0,0}, {0,1}, {-1,1}, {1,1} }; // ㅜ : 맨 아래가 기준


// 정 모르겠으면 노가다로 회전, 대칭한거 순서쌍으로 때려박으면 될 듯
// 회전 함수
void rotation(int** arr, int angle) {
	int quote = angle / 90;

	int x, y;
	// 90도 회전 (a,b) -> (-b, a) + -90도 회전은 (a,b) -> (b, -a)
	if (quote == 1) {
		for (int i = 0; i < 4; i++) {
			x = arr[i][0]; y = arr[i][1];
			arr[i][0] = -y;
			arr[i][1] = x;
		}
	}

	// 180도(90도 * 2) (a,b) -> (-b, a) -> (-a ,-b)
	if (quote == 2) {
		for (int i = 0; i < 4; i++) {
			x = arr[i][0]; y = arr[i][1];
			arr[i][0] = -x;
			arr[i][1] = -y;
		}
	}

	// 270도(90도 * 3) (a,b) -> (-b, a) -> (-a, -b) -> (b, -a)
	if (quote == 3) {
		for (int i = 0; i < 4; i++) {
			x = arr[i][0]; y = arr[i][1];
			arr[i][0] = y;
			arr[i][1] = -x;
		}
	}
}

// 대칭 함수
// x축, y축 대칭 함수
void symmetry(int** arr, int axis) {
	
	// x축 대칭(a,b) -> (-a, b)
	int x, y;
	if (axis == 0) {
		for (int i = 0; i < 4; i++) {
			arr[i][0] = -arr[i][0];
		}
	}

	// y축 대칭(a,b) -> (a, -b)
	else if (axis == 1) {
		for (int i = 0; i < 4; i++) {
			arr[i][1] = -arr[i][1];
		}
	}
}

int t1[4][2] = { {0,0}, {1,0}, {2,0}, {3,0} }; // ㅡ :맨 왼쪽이 기준
int t2[4][2] = { {0,0}, {1,0}, {0,1}, {1,1} }; // ㅁ :왼쪽 아래가 기준
int t3[4][2] = { {0,0}, {1,0}, {0,1}, {0,2} }; // L : 왼쪽 아래가 기준
int t4[4][2] = { {0,0}, {0,1}, {-1,1}, {-1,2} }; // ㄴㄱ: 맨 아래가 기준
int t5[4][2] = { {0,0}, {0,1}, {-1,1}, {1,1} }; // ㅜ : 맨 아래가 기준

void dfs(int** arr, int x, int y) {

	sum = 0;

	for (int i = 0; i < 4; i++) {
		x += arr[i][0]; y += arr[i][1];
		if (x < 0 || x > m || y < 0 || y > n) {
			return;
		}

		sum += numbers[x][y];
	}

	score = max(score, sum);

	x++;
	dfs(arr, x, y);
}

int main() {
	cin >> n >> m; // 세로 n, 가로 m

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> numbers[i][j];
		}
	}

	// 테트로미노 하나 당 for 5
	// 이동, 회전해서 이동, 대칭해서 이동 해서 max 구하기 -> dfs
	
	rotation(t1, 90);
	dfs(t1, 0, 0);
	rotation(t1, 180);

	rotation(t1, 270);

	symmetry(t1, 0);

	symmetry(t1, 1);


	//출력(최대값)
}

*/
