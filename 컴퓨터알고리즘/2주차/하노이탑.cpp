#include <stdio.h>
#include <stdlib.h>


void rHanoi(int n, char from, char aux, char to)
{
	if (n == 1)
		printf("Disk %d: Move from %c to %c\n", n, from, to);
	else
	{
		rHanoi(n - 1, from, to, aux);
		printf("Disk %d: Move from %c to %c\n", n, from, to);
		rHanoi(n - 1, aux, from, to);
	}
}

void main()
{
	rHanoi(4, 'A', 'B', 'C');
}
