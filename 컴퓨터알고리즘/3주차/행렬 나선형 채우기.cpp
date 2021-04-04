#include <stdio.h>
#include <algorithm>

#define SIZE 100
using namespace std;

// nxm 배열ㅉ
void spiral(int A[][SIZE], int n, int m)
{
	int left = 0; int right = m - 1;
	int top = 0; int bottom = n - 1;
	int value = 1;

	while (left <= right && top <= bottom)
	{
		// 왼쪽에서 오른쪽(top 고정)
		for (int j = left; j <= right; j++)
		{
			A[top][j] = value;
			value++;
		}
		top++;

		// 위에서 아래(right 고정)
		for (int i = top; i <= bottom; i++)
		{
			A[i][right] = value;
			value++;
		}
		right--;

		// 오른쪽에서 왼쪽(bottom 고정)
		for (int j = right; j >= left; j--) // 부등호 방향 조심
		{
			A[bottom][j] = value; // left-> right였으면 A[bottom][right-i]
			value++;
		}
		bottom--;

		// 아래에서 위(left 고정)
		for (int i = bottom; i >= top; i--) // 부등호 방향 조심
		{
			A[i][left] = value;
			value++;
		}
		left++;
	}
	
}

int main()
{
	int N, M;
	printf("n값을 입력하세요: ");
	scanf_s("%d %d", &N, &M);

	int arr[SIZE][SIZE] = { 0 };

	spiral(arr, N, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("[%2d]", arr[i][j]);
		printf("\n");
	}

	return 0;
}
