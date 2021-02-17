#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

// ** 자료구조 하나로 다 하려고 생각하지 말자.
// ** 필요에 의해 분리!!

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 0; test_case < t; test_case++) {
		int n, idx, cnt = 0;

		queue<pair<int, int>> q;
		priority_queue<int> pq; // 우선순위큐는 알아서 오름차순 정렬해줌

		scanf("%d %d", &n, &idx);
		for (int i = 0; i < n; i++) {
			int imp;
			scanf("%d", &imp);
			q.push({ i, imp });
			pq.push(imp);
		}

		while (!q.empty()) {
			// 현재 원소의 인덱스와 중요도
			int nowidx = q.front().first;
			int nowimp = q.front().second;
			q.pop();

			// 중요도가 가장 크면
			if (pq.top() == nowimp) {
				pq.pop();
				cnt++; // 몇번째로 출력되는지

				if (nowidx == idx) {
					printf("%d\n", cnt);
					break;
				}
			}
			else {
				// 맨 끝으로 보내버리기
				q.push({ nowidx,nowimp });
			}
		}
	}
	return 0;
}

/*
int t, n, idx; // 맨 왼쪽이 0 번째

struct cmp {
	//연산자 오버로딩
	bool operator()(pair<int, int>&a, pair<int, int>&b) {
		return a.second > b.second; // 두개의 데이터를 비교함에 있어서 왼쪽에 있는 것이 더 클 수 있도록 정렬 하겠다
								    // 즉, 내림차순!
	}
};

int main() {
	// 테스트 케이스
	cin >> t;

	int imp;
	for (int i = 0; i < t; i++) {
		// 문서 개수, 궁금한 문서 index
		cin >> n >> idx;
		// 중요도

		priority_queue<pair<int, int>> q;
		// priority_queue<pair<int, int>, vector<int,int>, cmp> q;
		// queue를 중요도 순으로 정렬 하는건데
		// pq는 첫번째 원소 기준으로 정렬을 default인 오름차순으로 해줘서 걍 그대로 쓰겠음

		for (int i = 0; i < n; i++) {
			cin >> imp;
			q.push(make_pair(imp, i));
		}

		// 출력
		pair<int, int> p;
		for (int i = 0; i < n; i++) {
			p = q.top();
			q.pop();

			cout << "페어: " <<p.first << ' ' << p.second << '\n';

			if (p.second == idx) {
				cout << i + 1 << '\n';
				break;
			}
		}
		// 문제점: 이렇게 하면 중요도가 겹칠 때 오름차순이 마음대로 되어버림 => 순서대로 뒤로 가고 해야함...
	}
}
*/
