#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define MAX 41

using namespace std;

int t, n;
int arr[MAX][2]; // 0 count, 1 count


// 피보나치 단순하게 빠르게 출력하는건 가능한데,
// 저 count를 어떻게 출력할지가 정말 곤란...
// 아니,, 걍 횟수만 출력하면 되네 이런 미친..ㅋㅋㅋ 

int fibonacci0(int n) {

	int &result = arr[n][0];

	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 0;
	}
	else if (result != -1) {
		return result;
	}
	
	return result = fibonacci0(n - 1) + fibonacci0(n - 2);
}

int fibonacci1(int n) {

	int &result = arr[n][1];

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (result != -1) {
		return result;
	}

	return result = fibonacci1(n - 1) + fibonacci1(n - 2);
}

int main() {
	cin >> t;

	memset(arr, -1, sizeof(arr));
	arr[0][0] = 1; arr[0][1] = 0;
	arr[1][0] = 0; arr[1][1] = 1;


	for (int i = 0; i < t; i++) {
		cin >> n;
		fibonacci0(n); fibonacci1(n);
		cout << arr[n][0] << ' ' << arr[n][1] << '\n';
	}
}

/*
규칙성 찾아서 쉽게 풀기
0의 출력 횟수 1, 0, 1, 1, 2, 3...
1의 출력 횟수 0, 1, 1, 2, 3, 5...

피보나치처럼 앞 횟수 더해가는게 맞음!(내풀이)
그렇기에 각자 서로 피보나치 수열을 또다시 이루는것.

즉, 0의 출력횟수는 N==0일때 1을 제외하고 0부터 시작하는 피보나치 수열,
1의 출력횟수는 N==0일 때부터 시작하는 피보나치 수열이다!
*/

#include <iostream>
using namespace std;
long arr[50] = {0, 1, }; // 초기값을 걍 여기서 바로 줄 수 있네

long fibo(int n){
	if(n == 0 || n == 1)
		return arr[n];
	else if(arr[n] == 0)
		arr[n] = fibo(n-1) + fibo(n-2);
	return arr[n];
}

int main(){
	int t;
	cin >> t;
	
	int tmp;
	for(int i=0; i<t; i++){
		cin >> tmp;
		if(tmp == 0)
			cout << "1 0" << '\n';
		else
			cout << fibo(tmp-1) << ' ' << fibo(tmp) << '\n';
	}
}
