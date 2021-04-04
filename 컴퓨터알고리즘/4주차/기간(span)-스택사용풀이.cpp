#include <stdio.h>
#include <stack>

using namespace std;

#define SIZE 6

void init(stack<int> A)
{
	A.top() = -1;
}

void spans(stack<int> A, int X[], int S[])
{
	for (int i = 0; i < SIZE; i++)
	{
		while (!A.empty() && X[A.top()] <= X[i])
			A.pop();
		if (A.empty())
			S[i] = i + 1; // 자기자신 인덱스 + 1
		else
			S[i] = i - A.top();

		A.push(i);
	}
	while (!A.empty())
		A.pop();
	return;
}

int main()
{
	int X[SIZE] = { 6, 3, 4, 2, 5, 3 };
	int S[SIZE] = { 0 };

	stack<int> A; // 초기화는 알아서 해줌

	spans(A, X, S);

	for (int i = 0; i < SIZE; i++)
		printf("[%d]", S[i]);
	printf("\n");

	return 0;
}
