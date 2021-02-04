#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
int t;
double x, y, dist, maxv, remain, result;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		dist = y - x;

		maxv = 0; // **초기화 중요!
		// 최대 속도 구하기
		while (maxv*maxv <= dist)
			maxv++;
		maxv--;

		remain = dist - maxv * maxv;

		result = ceil(remain / maxv); // ** 나누기 소수점 구하려면 double로 해야함!

		/* 올림을 직접 계산하려고 했는데 왜 틀려... 는 maxv =0 초기화 안해서지 코드가 틀린건 아니었음ㅋㅋㅋ
      			다만 이거 쓰려면 double 형이 아니라 long 형으로 바꿔줘야 한다!!(double은 %계산이 안됨!)
			
			if (remain % maxv == 0)
				result = remain / maxv;
			else
				result = remain / maxv + 1;
		*/

		cout << 2 * maxv - 1 + result << '\n';
	}

	return 0;

	// 1로 시작해서 1로 돌아와야 한다.
	// 즉 데칼코마니 같은 형태일듯 => 규칙을 알아내보자!
	// 최소 이동 횟수는 갈 수 있을 때 최고 속도를 내면 됨!
	// 거리 (1,2) (3,4) (5,6) 이렇게 묶여서 같은 ==> X 2개씩 단순히 묶이지 않음

	/*
		최대거리 : N^2 (1 2 3...N...3 2 1 인 경우가 최대 거리)
		워프 횟수: 2*N-1 (1에서 N까지 이동하고 데칼코마니처럼 다시 줄어드니까)
		최고 속도: N

		1. 최대 속도만큼 이동을 하고
		2. 모자란 거리만큼을 중간에 넣어주면 된다.(최대 이동속도를 넘지 않는 한에서, 필요한 거리(속도) 구하기만 하면 위치는 정해지므로)
			-> 여러 경우의 수가 있지만 횟수는 어차피 동일하므로, 쉽게 최대 이동속도를 한번 더 진행하고 나머지 속도를 넣어준다고 생각하면됨
		=> 즉 거리(d)가 주어졌을 때, 최고속도를 N, 남은 거리를 A라고 한다면
			d = N^N + A 일 때,
			최소 이동 횟수는 2N-1 + (A/N)의 올림값
	*/
}
