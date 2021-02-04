#include <algorithm>
#include <cmath>
#include <iostream>
#define MAX 301

using namespace std;

// Dynamic Programming

int n;
long result, sum;
int stair[MAX];
int DP[MAX]; // 해당 계단까지의 MAX값을 나타내는 배열

int main() {
	// 계단의 개수
	cin >> n;

	// 0은 시작 계단
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	
	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];
	DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= n; i++) {
		// 점화식
		// 1. 마지막 계단 전의 계단을 밟지 않은 경우
		// 2. 마지막 계단 전의 계단을 밟은 경우
		DP[i] = max(stair[i] + DP[i - 2], stair[i] + stair[i - 1] + DP[i - 3]);
	}

	cout << DP[n] << '\n';
}

// 올라가는건 너무 복잡함... 내려가는걸로 해야겠어.. 재귀로 안해도 될듯..


// 그냥 그 전에 1칸 올라왔으면 그 다음에도 1칸 올라오면 무조건 3칸 연속이 되는 거임!
// 1칸 올라왔으면 그 다음에는 무조건 2칸 가게 하도록 하면 된다!
// 근데 재귀는 너무 계산량이 늘어날듯,,, memoization 필수! 거기까지 계단을 계산하는것,,,
// 어떻게 작성해야하는지 차암..
/*
https://kibbomi.tistory.com/66
int n;
long result, sum;
int stair[MAX];
int DP[MAX][2]; // 해당 계단까지의 MAX값을 나타내는 배열

int up(int now, int cnt) {

	int &cache = DP[now][cnt];
	if(cache != -1) return DP[now][cnt];

	// 그 전에서 2칸으로 올라왔을 때
	if(cnt == 0){
		return DP[now][[0] = max(up(now-2, 0), up(now-2,1)) + stair[now];
	}
	// 그 전에서 1칸으로 올라왔을 때, 2칸으로 올라온 그 전값에다가 더함
	else if(cnt == 1){
		return DP[now][1] = up(cur-1,0) + stair[now];
	}
}

int main() {
	// 계단의 개수
	cin >> n;

	// 0은 시작 계단
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	memset(DP, -1, sizeof(DP));

	DP[0][0] = DP[0][1] = 0;
	DP[1][0] = stair[1];

	cout << max(up(n,0), up(n,1)) << '\n';
}
*/
