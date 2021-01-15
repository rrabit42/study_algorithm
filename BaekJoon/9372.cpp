#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/*
	Minimum Spanning Tree:
	그래프에서 그래프의 모든 정점을 연결하되, 사이클이 존재하지 않도록 모든 정점을 간선으로 연결하는 것!
	이때, 간선의 가중치 합을 최소로 하며 연결해야함.

	- Kruskal's Algorithm
		모든 간선에 대해 가장 가중치가 작은 간선부터 연결해주면서 MST를 만들어 나가는 알고리즘.
		연결하는 도중 사이클이 생기게 된다면 가중치가 작은 간선이어도 무시한다.

	- Prim's Algorithm
		하나의 시작점을 잡고 시작점과 연결된 정점들에 대해 가장 가중치가 작은 선부터 연결해주면서 MST를 만들어 나가는 알고리즘.
		연결하는 도중 사이클이 생기게 된다면 가중치가 작은 간선이어도 무시한다.

*/

// 해당문제에서 edge에 가중치는 존재하지 않고, 모든 노드를 방문할 수 있는 최소 엣지 방문 횟수
// MST는 항상 간선의 개수가 N-1이다!!!!!! N은 노드수
// 이 문제에서 N-1이 그냥 답이다. 모든 노드를 가려면 최소 N-1 이동해야하니까ㅋㅋㅋ

int main() {
	// 그냥 입력받고 바로 출력해도 됨.
	int T, N, M, a, b;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b; // 어차피 얘넨 연산에 필요 없음ㅋ
		}
		cout << N - 1 << endl;
	}
}
