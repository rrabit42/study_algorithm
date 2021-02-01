#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101

using namespace std;

int n, u;
int arr[MAX][MAX] = { 0, }; // 1번부터 들어가니까! 0은 사용X
int cnt = 0;
queue<int> q;
int visited[MAX] = { 0, };

void BFS(int start) {
	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		start = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[start][i] == 1 && visited[i] == 0) {
				visited[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
}

int main() {
	// 컴퓨터의 수, 100 이하
	cin >> n;

	// 직접 연결되어 있는 컴퓨터쌍의 수
	cin >> u;

	int a, b;
	for (int i = 0; i < u; i++) {
		cin >> a >> b;

		arr[a][b] = arr[b][a] = 1;
	}

	// 1번 컴퓨터가 웜 바이러스에 걸렸을 때,
	// BFS 이용
	BFS(1);
	cout << cnt<< '\n'; //visited==1인 개수를 구해도 됐을 듯!
	return 0;
}

/*
#include <iostream>
#include <queue>
using namespace std;

int M, N, x, y; //M :정점 수, N : 간선 수
int visited[101]; // 방문한 노드 표시
int adj[101][101]; // 인접 행렬 ㅍ시
int ans = -1; // 1번과 연결 된 컴퓨터의 개수 세기(1번컴퓨터는 개수에서 제외 -1)
queue<int> q; // 큐

void bfs(int v)
{
	visited[v] = 1; // bfs를 시작하는 정점에 방문표시
	q.push(v); // 큐 삽입

	while (!q.empty())
	{
		v = q.front(); // 큐의 맨앞 = v
		q.pop(); // 큐 맨앞 삭제
		ans++; // 큐에 들어왔다는 뜻은 시작 노드와 연결(직접 and 간접)되어있다는 뜻!
		for (int i = 1; i <= M; i++)
		{
			if (visited[i] == 1 || adj[v][i] == 0) continue; // 방문한적 있거나 인접한 점이 없다면 패스

			visited[i] = 1; // 방문표시
			q.push(i); // 큐 삽입
		}
	}
}

int main()
{
	cin >> M; // 정점 수
	cin >> N; // 간선 수

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		adj[x][y] = adj[y][x] = 1; // 인접행렬표시
	}

	bfs(1); // 시작 노드
	cout << ans;
}
*/
