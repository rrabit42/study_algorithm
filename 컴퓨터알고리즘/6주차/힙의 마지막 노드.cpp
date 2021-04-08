#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

struct Heap
{
	int value[MAX_ELEMENT];
	int n;
}heap;

struct Stack
{
	int element[MAX_ELEMENT];
	int top;
}stack;

// stack 관련 함수들
void initStack(Stack *stack)
{
	stack->top = -1;
}

bool isEmpty(Stack *stack)
{
	if (stack->top == -1)
		return true;		// 비었다
	return false;
}

void push(Stack *stack, int n)
{
	stack->top += 1;
	if (stack->top > MAX_ELEMENT)
	{
		printf("스택이 꽉 찼습니다. 더 추가할 수 없습니다.");
		exit(1);
	}
	stack->element[stack->top] = n;
	return;
}

int pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		printf("스택이 비었습니다. pop할 원소가 없습니다.");
		exit(1);
	}
	int n = stack->element[stack->top];
	stack->top -= 1;
	return n;
}

// heap 관련 함수들
void initHeap(Heap *h)
{
	h->n = 0;
}

// 최소힙
void upHeap(Heap *h)
{
	int i = h->n;
	int value = h->value[i];

	// root가 아니고, 최근에 넣은 값이 부모보다 작으면
	while ((i != 1) && (value < h->value[i / 2]))
	{
		h->value[i] = h->value[i / 2];	// 부모 노드 값 아래로 내리기
		i /= 2;							// up
	}
	h->value[i] = value;
}

void insertHeap(Heap *h, int value)
{
	h->n += 1;
	h->value[h->n] = value;
	upHeap(h);
}

void printHeap(Heap *h)
{
	for (int i = 1; i <= h->n; i++)
		printf("[%d] ", h->value[i]);
	printf("\n");
}

int leftChild(int v, Stack *stack)
{
	return v * 2;
}

int rightChild(int v, Stack *stack)
{
	return v * 2 + 1;
}

// 이진수 찾기
void binaryExansion(int i, Stack *stack)
{
	while (i >= 2)
	{
		push(stack, i % 2);
		i /= 2;
	}
	push(stack, i);
	return;
}

// 힙의 마지막 노드 찾기
int findLastNode(int v, int n)
{
	initStack(&stack);
	binaryExansion(n, &stack);
	
	// 최상위 비트는 제거
	pop(&stack);

	while (!isEmpty(&stack))
	{
		int bit = pop(&stack);
		if (bit == 0)
			v = leftChild(v, &stack);
		else
			v = rightChild(v, &stack);
	}
	return v;
}

int main()
{
	srand(time(NULL));

	initHeap(&heap);
	for (int i = 0; i < 10; i++)
		insertHeap(&heap, rand() % 100 + 1);
	printHeap(&heap);

	int last = findLastNode(1, heap.n);
	printf("힙의 마지막 노드는 %d입니다.\n", heap.value[last]);

	return 0;
}
