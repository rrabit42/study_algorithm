#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DListNode
{
	int elem;
	struct DListNode* prev, *next;
}DListNode;

typedef struct
{
	DListNode* H;
	DListNode* T;

}SetType;

void initNode(DListNode* H, DListNode* T)
{
	H->next = T;
	T->prev = H;
}

DListNode* getnode()
{
	DListNode *p = (DListNode*)malloc(sizeof(DListNode));
	return p;
}

void initSet(SetType* s)
{
	s->H = getnode();
	s->T = getnode();
}

void addLast(SetType* s, int item)
{
	DListNode *node = (DListNode*)malloc(sizeof(DListNode));
	node->elem = item;

	node->next = s->T;
	node->prev = s->T->prev;
	s->T->prev->next = node;
	s->T->prev = node;
}

void printList(SetType* s)
{
	for (DListNode* p = s->H->next; p != s->T; p = p->next)
	{
		printf("[%d] ", p->elem);
	}
	printf("\n");
}

void selection_sort(SetType *s)
{
	int least, temp;
	for (DListNode* search = s->H; search != s->T->prev; search = search->next)
	{
		// 포인터까지 같이 교환되어버려서 next 노드를 바꾸는걸로!
		DListNode* p = search->next;
		DListNode* least = search->next;

		for (DListNode* q = p->next; q != s->T; q = q->next)
		{
			if (q->elem < least->elem)
			{
				least = q;
			}
		}

		// SWAP
		DListNode *temp = p->prev;

		p->prev->next = least;
		p->prev = least->prev;

		least->prev->next = p;
		least->prev = temp;

		temp = p->next;

		p->next->prev = least;
		p->next = least->next;

		least->next->prev = p;
		least->next = temp;
	}
}

void delete_duplication(SetType *s)
{
	// 뒤로 같은 element 있으면 삭제
	for (DListNode* search = s->H; search != s->T->prev->prev; search = search->next)
	{
		DListNode* now = search->next;
		DListNode* daum = now->next;

		// now의 다음 노드(daum)을 지운다
		if (now->elem == daum->elem)
		{
			now->next = daum->next;
			daum->next->prev = now;

			daum->prev = NULL;
			daum->next = NULL;
			free(daum);
		}
	}
}

void makeListToSet(SetType* s)
{
	// 선택 정렬 후
	selection_sort(s);

	// 중복삭제
	delete_duplication(s);
}

bool hasElement(SetType* s, int key)
{
	for (DListNode* p = s->H->next; p != s->T; p = p->next)
	{
		if (p->elem == key)
			return true;
	}
	return false;
}

void plus_set(SetType* s, SetType* a, SetType* b)
{
	for (DListNode* p = a->H->next; p != a->T; p = p->next)
	{
		addLast(s, p->elem);
	}
	for (DListNode* q = b->H->next; q != b->T; q = q->next)
	{
		addLast(s, q->elem);
	}
	selection_sort(s);
	delete_duplication(s);
}

void minus_set(SetType* s, SetType* a, SetType* b)
{
	DListNode* p = a->H->next;
	while (p != a->T) {

		if (!hasElement(b, p->elem))
		{
			addLast(s, p->elem);
		}
		p = p->next;
	}
}


int main() {
	SetType* s1 = (SetType*)malloc(sizeof(SetType));
	initSet(s1);
	SetType* s2 = (SetType*)malloc(sizeof(SetType));
	initSet(s2);

	initNode(s1->H, s1->T);
	initNode(s2->H, s2->T);

	int num;
	printf("원소의 개수 입력 : ");
	scanf("%d", &num);

	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		int item = rand() % 30 + 11;
		addLast(s1, item);
	}
	for (int i = 0; i < num; i++)
	{
		int item = rand() % 30 + 11;
		addLast(s2, item);
	}

	printf("\n");
	printf("리스트 A : ");
	printList(s1);
	printf("리스트 B : ");
	printList(s2);

	printf("\n");
	printf("선택정렬 - 집합 A : ");
	makeListToSet(s1);
	printList(s1);
	printf("선택정렬 - 집합 B : ");
	makeListToSet(s2);
	printList(s2);

	printf("\n");
	printf("A와 B의 합집합 : ");
	SetType* plus = (SetType*)malloc(sizeof(SetType));
	initSet(plus);
	initNode(plus->H, plus->T);

	plus_set(plus, s1, s2);
	printList(plus);

	printf("A와 B의 차집합 : ");
	SetType* minus = (SetType*)malloc(sizeof(SetType));
	initSet(minus);
	initNode(minus->H, minus->T);

	minus_set(minus, s1, s2);
	printList(minus);
}
