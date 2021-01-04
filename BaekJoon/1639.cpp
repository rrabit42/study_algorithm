#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

#define MAX 50
string arr[MAX]; // 전역이니까 모든 원소가 0이 됐을거야

string Ticket;

int main() {
	cin >> Ticket;
	int len = Ticket.length();

	int start, end, mid;
	end = len % 2 == 0 ? len : len - 1;

	int sum_a, sum_b;
	int s, e;

	// while문 들어가자마자 -2 당하므로 여기서 더 해주고 간다.
	end += 2;

	// 검사하는 문자열 길이는 2 이상이어야 한다.
	while (end >= 2) {
		start = 0;
		end -= 2;

		s = start;
		e = end;
		while (e <= len) {
			mid = (s + e) / 2;

			sum_a = 0; sum_b = 0;
			// mid 기준 왼쪽
			for (int i = s; i < mid; i++) {
				sum_a += Ticket[i];
			}
			// mid 기준 오른쪽
			for (int i = mid; i < e; i++) {
				sum_b += Ticket[i];
			}

			// 합이 같으면 총 문자열 길이 return
			if (sum_a == sum_b) {
				cout << end;
				return 0;
			}
			s++; e++;
		}
	}
	cout << 0;
	return 0;
}
