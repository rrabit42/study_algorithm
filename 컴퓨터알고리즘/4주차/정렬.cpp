#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_SIZE 15
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y)=(t))

void selection_sort(int list[], int n)
{
	int least, temp;
	for (int i = 0; i < n - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < n; j++)
			if (list[j] < list[least])
				least = j;
		SWAP(list[i], list[least], temp);
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, save;
	for (i = 1; i < n; i++)
	{
		save = list[i];
		for (j = i - 1; j >= 0 && list[j] > save; j--)
			list[j + 1] = list[j];
		list[j + 1] = save;
	}
}

void bubble_sort(int list[], int n)
{
	int temp;
	for (int i = n - 1; i >= 0; i--)
	{
		printf("\n %d 단계 >>\n", n - i);
		for (int j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
		for (int t = 0; t < n; t++)
			printf("%3d ", list[t]);
	}
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first+gap; i <=last; i=i+gap)
	{
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j = j-gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n)
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2)
	{
		// gap이 홀수일 때가 효율이 더 높으니까
		if (gap % 2 == 0)
			gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}

int main()
{
	int list[MAX_SIZE];
	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = rand() % 100;
		// 중복 제거
		for (int j = 0; j < i; j++)
		{
			if (list[i] == list[j])
				i--;
		}
	}

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n\n");

	// selection_sort(list, MAX_SIZE);
	// insertion_sort(list, MAX_SIZE);
	// bubble_sort(list, MAX_SIZE);
	shell_sort(list, MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", list[i]);
		Sleep(500);
	}
	printf("\n\n");
}
