#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// 1. Dynamic Programming(DP)
// * 2. 경우의 수가 적으면 -> 재귀함수로 dfs를 이용해 가능한 경우의 수 따지기
// 3. Greedy Algorithm(탐욕 알고리즘)

int n;
int time[15] = { 0, };
int pay[15] = { 0, };
int max_pay = 0;

void calculate(int i, int now_pay) {
	// 간단하게 생각하자: 그 날에 고객을 상담하냐/안하냐

	// index 초과
	if (i == n) {
		max_pay = max(max_pay, now_pay);
		return;
	}

	// 상담 기간이 초과가 안된 경우
	if (i + time[i] <= n) {
		calculate(i + time[i], now_pay + pay[i]); // 그럼 일당을 받을 수 있지
	}

	// 다른 경우의 수도 살펴보자.
	if (i + 1 <= n) { // =인 이유는 7일 때 index 초과로 종료를 시키기 위함
		calculate(i + 1, now_pay);
	}
}


int main() {
	// 입력 받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		// cin >> time[i] >> pay[i]; 이렇게 쓸 수도 있음
		cin >> time[i];
		cin >> pay[i];
	}

	// dfs
	calculate(0, 0);

	// 출력
	cout << max_pay << endl;
	return 0;
}


// 첫시도
/*
		- 상담을 할 수 없는 경우
			1. index 초과 -> calculate의 끝
			2. 상담시간이 초과됨 -> 그 다음 인덱스로 넘어감

		문제1:
			문제는 상담시간이 초과됐을 당시 index가 마지막 index였을 때 now_pay를 돌려주는데
			그게 if문안에서 돌려줌
			=> now_pay -= pay[i] 추가함

		문제2:
			이렇게 했는데 예제4에서 걸림....
			아마 이 문제인듯
			나는 순서대로 더해나가는 건데, 그 순서 말고 건너뛰고 더하는게 더 좋은 경우.
			ex) 1 ->3,4 선택지가 있는데 난 3만 항상 선택하는데 3 무시하고 4를 선택했을 경우가 더 좋은 선택일 경우.
			얜 재귀 함수 쪽을 고쳐야 함!
			즉, 내가 취할 수 있는 갈림길을 모두 가보는 것!
			그럼 calculate() 함수 한번 돌 때 여러 경우의 수에 따른 출력값이 나오기 때문에,
			비교 자체를 main이 아닌 여기서 해줘야 한다. => 싹다 뜯어 고쳐야함

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int n;
int time[15] = { 0, };
int pay[15] = { 0, };
int max_pay = 0, now_pay = 0;

int calculate(int i, int now_pay) {
	// index 초과
	if (i >= n) {
		return now_pay;
	}

	// 시간 초과되어 할 수 없는 상담 제외
	if ((i + time[i] - 1) >= n) {
		calculate(i + 1, now_pay); // *이거 재귀 갔다가 다시 돌아옴!
		now_pay -= pay[i];
	}

	now_pay += pay[i];
	calculate(i + time[i], now_pay); // *다음에 할 수 있는 상담으로 넘어가기 -> ㄴㄴ 여러 선택지를 줘야함
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		// cin >> time[i] >> pay[i]; 이렇게 쓸 수도 있음
		cin >> time[i];
		cin >> pay[i];
	}


	// 여러 경우의 수 중에서 최고의 pay를 구하기
	for (int i = 0; i < n; i++) {
		// index 0일때부터 계산, time이 0보다 크면 pay더하고
		// 일 끝난 시점으로 jump 후 또 pay더함.
		now_pay = 0;
		now_pay = calculate(i, now_pay);
		if (now_pay > max_pay) {
			max_pay = now_pay;
		}
	}

	cout << max_pay << endl;

	return 0;
}
*/
