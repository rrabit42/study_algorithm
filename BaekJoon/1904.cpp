#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

#define MODULER 15746
#define N 1000000+1

using namespace std;

int n;
int arr[N] = {0, };

void input() {
	cin >> n;
    
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
}

void solution(){

	for(int i=3; i<=n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % MODULER;
        
    }
	cout << arr[n] << '\n';
}


int main() {
	input();
	solution();
}


/*
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

#define N 1000000

using namespace std;

int n;
int arr[N] = {0, };

void input() {
	cin >> n;

	// 초기화좀...
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
}

// 아니 밑에건 왜 정답이 안되는걸까
// 숫자를 크게하니 출력이 안됨ㅋ 왜?? 갑자기 그냥 끊김...
int dynamic(int n) {
	int &value = arr[n];

	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	// value에 값이 아직 안채워졌을 때
	else if (value != 0) {
		return value;
	}

	return value = (dynamic(n - 1) + dynamic(n - 2)) % 15746; // 저장할 때 값 넘길 수 있으므로
}

void solution(){
	// 00 아니면 1 조각 이용
	/*
		N(1) = 1		1
		N(2) = 2		00 11
		N(3) = 3		100, 111, 001
		N(4) = 5		1100, 1001, 1111, 0000, 0011 -> 1111로 이루어진애는 뒤에붙으나 앞에 붙으나 똑같음
		N(5) = 8		00100, 10000, 00111, 11100, 00001, 10011, 11111, 11001, 00111(X), 00100(X), 11100(X), 11111(X)

		즉 1로 이루어진 수열빼고는 다 2개씩 증식함
		그럼 식은 N(n) = N(n-1)*2 -1 임!
		인줄 알았는데 아님... 새롭게 생길 수도 있지...
		+ 100, 001 에서 둘다 1001이 만들어질 수 있음
		+ 4개일 때 0000이라는애가 새로 탄생 가능

		그럼 무슨 규칙이 있을까? 00 or 11
		홀수/짝수 나눠보자
		1에서 시작하는 홀수는 2개 늘어나는데 N(n-2)*2 -1 (00이 앞에붙거나 뒤에 붙거나, 11은 
		2에서 시작하는 짝수는...

		결국 블로그 참고했다: https://blog.naver.com/occidere/220787441430
		걍 느낌상 피보나치같이 dp[n] = dp[n-1] + dp[n-2] 같은데 맞대!
		-> n-2번째에서 "맨 뒤에" 00을 붙여만드는 경우의 수의 합 + n-1째에서 "맨 앞에" 1을 붙여 만드는 경우의 수의 합
		Q> 왜 n-2에서 11을 붙여만드는 수는 고려X? i-1에서 1을 붙여 만드는 경우와 중복돼서!

		그냥 붙이는거면 뒤/앞해서 2가지씩인데 그럼 중복되는거 빼기 번거로움
		-> 0은 뒤에 붙이고, 1은 앞에 -> 자연스럽게 중복 제거
	*/
	int result = dynamic(n);
	// 왜 틀렸나했더니 15746으로 나누어줘야함..
	cout << result << '\n';
}


int main() {
	input();
	solution();
}
*/
