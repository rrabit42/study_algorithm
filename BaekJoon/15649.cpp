#include <iostream>
#define MAX 9
using namespace std;

/*
	백트래킹은 모든 가능한 경우의 수 중에서 특정한 조건을 만족하는 경우만 살펴보는 것입니다.

	즉 답이 될 만한지 판단하고 그렇지 않으면 그 부분까지 탐색하지 않고,
	가지치기 하는 것을 백트래킹이라고 생각하면 됩니다.
	
	주로 문제 풀이에서는 DFS 등으로 모든 경우의 수를 탐색하는 과정에서,
	조건문 등을 걸어 답이 절대로 될 수 없는 상황을 정의하고,
	그러한 상황일 경우에는 탐색을 중지시킨 뒤 그 이전으로 돌아가서 다시 다른 경우를 탐색하게끔 구현할 수 있습니다
*/

int print[MAX] = {0, };
int visited[MAX] = {0, };
int m, n; // 1~n까지의 자연수 중에서 중복없이 m개를 고른 수열

// 총 nPm 개의 수열이 만들어짐. n!/(n-m)!
// ** DFS로 순열을 구할 수 있음. DFS를 이용한 백트래킹 방식 이해하기!

// DFS
// 숫자를 앞에서부터 한개씩 뽑으면서 visited가 m개 만큼 1이 되면 출력!
void find(int cnt) {

	// 각 수열은 공백으로 구분
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << print[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 사전 순서로 증가
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {

			visited[i] = 1;
			print[cnt] = i;
			find(cnt+1); // ** cnt++하면 find 재귀 다 끝난 다음에 +1 됨...
						 // ** ++cnt 하면 cnt를 다시 0으로 초기화 시켜 줘야함! cnt = cnt + 1이기 때문
						 // ** 그래서 그냥 cnt+1하면 cnt값은 안변하는데 재귀 돌때만 +1된 채로 돌게 되는 것!!!!!!!!!
			visited[i] = 0; // 다 살펴봤으니까 다음! 숫자
		}
	}
}

int main() {
	cin >> n >> m;

	find(0);

	return 0;
}
