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

int remove(int A[], int n, int r)
{
	if ((r < 0) || (r > n - 1))
	{
		printf("invalidRankException...");
		exit(1);
	}

	for (int i = r + 1; i < n; i++)
	{
		A[i - 1] = A[i];
	}
	n--;
	return n;
}

// ver.2
int runSimulation(int A[], int n, int k)
{
	int r = 0;
	while (n > 1)
	{
		r = (r + k) % n;
		n = remove(A, n, r);
	}
	return A[0];
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
