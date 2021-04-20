#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void partition(char list[], int left, int right)
{
	int low = left - 1, high = right + 1; // do while 위해
	char temp;

	do
	{
		do
			low++;
		while (list[low] == 'B');
		do
			high--;
		while (list[high] == 'R');

		if (low < high)
			SWAP(list[low], list[high], temp);

		printf("low = %d, high =%d\n\n", low, high);
		for (int i = 0; i < MAX_SIZE; i++)
			printf("[%c] ", list[i]);
		printf("\n");

	} while (low < high);
}

int main()
{
	char list[MAX_SIZE];
	srand(time(NULL));

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (rand() % 2 == 0)
			list[i] = 'B';
		else
			list[i] = 'R';
	}

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%c] ", list[i]);
	printf("\n");

	partition(list, 0, MAX_SIZE - 1);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("[%c] ", list[i]);
	printf("\n");
}
