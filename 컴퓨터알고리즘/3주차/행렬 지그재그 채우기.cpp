#include <stdio.h>
#include <algorithm>

#define SIZE 100
using namespace std;

void zigzag(int A[][SIZE], int n)
{
	int value = 1;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++)
			{
				A[i][j] = value;
				value++;
			}
		}
		else
		{
			for (int j = n - 1; j >= 0; j--)
			{
				A[i][j] = value;
				value++;
			}
		}
	}
}

int main()
{
	int N;
	printf("n값을 입력하세요: ");
	scanf_s("%d", &N);

	int arr[SIZE][SIZE] = { 0 };

	zigzag(arr, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("[%2d]", arr[i][j]);
		printf("\n");
	}

	return 0;
}
