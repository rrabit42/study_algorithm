#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, k; // nxn 땅, m개의 나무, k년 후
int A[11][11] = { 0 };		// 상도의 땅
int energy[11][11] = { 0 };	// 겨울에 뿌릴 비료 정보
vector<int> tree[11][11];	// 이 자료형 정하는게 어려웠음,,
							// vector, deque를 이렇게 2차원 배열로 만들 수 있음
							// pop_front()가 없어서 deque로 바꿈
int x[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };


void fourseason() {

	// 봄: 자신의 나이만큼 양분 먹고, 나이 +1
	// 나무가 있는 1x1 크기의 칸에 있는 양분만, 어린 나무부터, 양분 부족해서 자신의 나이만큼 못먹으면 죽음

	// 여름: 봄에 죽은 나무가 양분으로 변함
	// 죽은 나무 나이 / 2 가 양분으로 추가됨

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 나무가 그 구역에 없으면
			int size = tree[i][j].size();
			if (size == 0) continue;	// size는 벡터가 생성된 크키

			// 나무가 그 구역에 있으면
			int DeadTreeEnergy = 0;
			vector<int> Temp;

			// 나이 순서대로 정렬
			sort(tree[i][j].begin(), tree[i][j].end());	// begin < end가 default
			// Spring
			for (int k = 0; k < size; k++) {
				int age = tree[i][j][k];

				// 양분 체크
				if (A[i][j] >= age) {
					A[i][j] -= age;
					age++;
					Temp.push_back(age);			// 단순히 값 바꾸는건 tree[i][j][k] = age
				}
				else {
					// 양분이 부족해 나무는 죽음
					// Summer 대비
					DeadTreeEnergy += (age / 2);
				}
			}
			// Summer
			tree[i][j].clear();		// clear 안하면 size가 그대로 남아있는 듯 하다.. 죽어서 없어질 수도 있는건데,,
									// size에서 push_back하면 더 추가될 뿐, pop한다고 size가 줄어드는건 아님,,
			for (int k = 0; k < Temp.size(); k++) {
				tree[i][j].push_back(Temp[k]);
			}
			A[i][j] += DeadTreeEnergy;
		}
	}

	// 가을: 나무 번식
	// 번식하는 나무의 나이는 5의 배수, 인접한 8개에 칸에 나이가 1인 나무가 생김
	// (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1)
	// 상도의 땅을 벗어나는 칸에는 생기지 X
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			int size = tree[i][j].size();
			if (size == 0) continue;

			// 나이가 5의 배수 이면
			for (int k = 0; k < size; k++) {
				int age = tree[i][j][k];

				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nx = i + x[k];
						int ny = j + y[k];
						// 상도의 땅 안에 있을 때
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}

	// 겨울: 땅에 양분 추가
	// 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A[i][j] += energy[i][j];
		}
	}

}

void input() {
	// 가장 처음에 양분은 모든 칸에 5
	// memset(A, 5, sizeof(A)); -> 오류

	cin >> n >> m >> k;

	// 양분의 양
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			A[i][j] = 5;
			cin >> energy[i][j];
		}
	}

	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		tree[x][y].push_back(z);	// 나무의 위치정보 및 나이 저장
									// 한 구역에 나무 여러개 있어도 동일한 좌표에 저장
	}
}

int main() {
	input();

	// K년 흐름
	for (int i = 0; i < k; i++) {
		fourseason();
	}

	// K년이 지난 후 상도의 땅에 살아있는 나무의 개수
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += tree[i][j].size();
		}
	}

	cout << cnt << '\n';

	return 0;
}
