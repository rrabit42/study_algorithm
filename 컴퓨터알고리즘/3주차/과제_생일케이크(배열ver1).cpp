#include <stdio.h>
#include <stdlib.h>

#define N 7
#define K 3


// 배열 초기화
void buildList(int A[], int n)
{
	for (int r = 0; r < n; r++)
		A[r] = r + 1;
	return;
}

// ver.1
int runSimulation(int A[], int n, int k)
{
	int r = 0;
	while (n > 1)
	{
		// blow 할 양초 찾기
		int i = 0;
		while (i < k) {
			r = (r + 1) % N;
			if (A[r] != 0)
				++i;
		}

		// 촛불 끄기
		A[r] = 0;
		--n;

		// 다음 양초 찾기
		while (A[r] == 0) {
			r = (r + 1) % N;
		}
	}
	return A[r];
}

// 양초 불기
int candle(int A[], int k)
{
	buildList(A, N);
	return runSimulation(A, N, K);
}

int main()
{
	int A[N] = { 0, };

	printf("특수 양초의 위치는 %d번 입니다.\n", candle(A, K));
}
