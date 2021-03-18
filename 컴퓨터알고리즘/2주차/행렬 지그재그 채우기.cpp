#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printArray(int A[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%2d ", A[i][j]);
		printf("\n");
	}
}

void zigzag(int A[][SIZE])
{
	int value = 1;
	
	// row
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			for (int j = 0; j < SIZE; j++)
			{
				A[i][j] = value;
				value++;
			}
		else
			for (int j = SIZE - 1; j >= 0; j--)
			{
				A[i][j] = value;
				value++;
			}
	}
}

int main()
{
	int A[SIZE][SIZE] = { 0, };
	zigzag(A);
	printArray(A);
}
