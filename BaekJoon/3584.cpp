#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

/*
	Lowest Common Ancestor(LCA) 알고리즘: 최소 공통 조상을 찾는 알고리즘
	두 정점에서 가장 가까운 공통 조상을 찾는 과정
	1. 세그먼트 트리 이용
	2. DP(Dynamic Programming) 이용(https://velog.io/@lre12/LCA-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98Lowest-Common-Ancestor)
		- 구하는 두 정점의 높이(깊이)를 먼저 동등하게 맞춰줘야함(깊은 애를 얕은 레벨로 끌어올리기)
		- 결과적으로 각 노드의 부모와 레벨을 알아야한다. (필요한 것: 각 노드의 부모, 레벨, 트리)
		- 각 노드의 부모 노드와 레벨을 저장한다.(DFS를 돌면서)
		- 재귀를 한번씩 돌 때마다 레벨을 1씩 올리면서! (바텀 업)
		- 최악의 경우 정점에 개수와 비례하게 탐색, O(N)

		- O(logN)만에 처리하는 법
		- 전처리: 
*/

int T, N;
vector<vector<int> > V;
vector<int> parent;
vector<int> depth;

void dfs(const int& here, const int& dep) {
	depth[here] = dep;
	for (int i = 0; i < V[here].size(); i++) {
		int there = V[here][i];
		dfs(there, dep + 1);
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		//1번부터 N번까지 공간 할당
		V.assign(N + 1, vector<int>());
		parent.assign(N + 1, 0);
		depth.assign(N + 1, 0);

		//input data 처리
		int u, v;
		for (int i = 0; i < N - 1; i++) {
			cin >> u >> v;
			V[u].push_back(v);
			parent[v] = u;
		}


		for (int i = 1; i <= N; i++) {
			if (!parent[i]) {
				parent[i] = i;
				dfs(i, 1);
				break;
			}
		}

		cin >> u >> v;
		while (depth[u] != depth[v]) {
			if (depth[u] < depth[v]) {
				v = parent[v];
			}
			else {
				u = parent[u];
			}
		}
		while (u != v) {
			v = parent[v];
			u = parent[u];
		}

		cout << v << endl;

	}
}
