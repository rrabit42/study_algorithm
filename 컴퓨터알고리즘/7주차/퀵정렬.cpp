#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int partition(int list[], int left, int right)
{
	int pivot, temp, low, high;
	
	low = left;
	high = right + 1;	// do while 문 쓸거라서
	pivot = list[left];

	// 
	do
	{
		do
			low++;
		while (list[low] < pivot);

		do
			high--;
		while (list[high] > pivot);

		// 과정 보기
		for (int i = 0; i < MAX_SIZE; i++)
			printf("[%d] ", list[i]);
		printf("\low = %d, high = %d\n", low, high);

		if (low < high)
			SWAP(list[low], list[high], temp);
	} while (low < high);

	// high는 pivot보다 작은 애중에 가장 오른쪽에 있는 애
	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);
		// q는 고정됐으니 sort에서 빠짐
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main()
{
	int list[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");

	quick_sort(list, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n\n");
}
