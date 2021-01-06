#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	// 괜히 어렵게 생각했다ㅜㅜ for 4중으로 쓰면 너무 오래 걸릴까봐 수학적 수식을 이용하려고 했는데
	// 초기값, 범위 설정이 중요한 문제였음
	// 딱히 변수 선언할 필요도, pow() 쓸 필요도 없었음

	// a > b > c > d 임을 파악하자! (근데 b,c,d 끼리는 서로 같아도 되지 않나.?
	for (int i = 6; i <= 100; i++) {
		for (int j = 2; j < i; j++) {
			for (int k = j + 1; k < i; k++) {
				for (int l = k + 1; l < i; l++) {
					if (i*i*i == (j*j*j + k * k*k + l * l*l)) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
					}
				}
			}
		}
	}
	return 0;
}
