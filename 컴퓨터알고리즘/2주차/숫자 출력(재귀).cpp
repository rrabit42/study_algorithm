#include <stdio.h>
#include <stdlib.h>


void rPrintDigits(int n)
{
	if (n < 10)
		printf("%d\n", n);
	else 
	{
		rPrintDigits(n / 10);
		printf("%d\n", n % 10);
	}
}

void printDigits()
{
	int n;
	printf("Enter a number : ");
	scanf("%d", &n);
	if (n < 0)
		printf("Negative!");
	else
		rPrintDigits(n);
}

void main()
{
	printDigits();
}
