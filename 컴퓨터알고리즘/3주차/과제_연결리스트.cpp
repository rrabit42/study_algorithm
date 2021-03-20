#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* link;
}ListNode;

typedef struct
{
	ListNode* head;
	int n;
}LinkedListType;

void init(LinkedListType* L)
{
	L->head = NULL;
	L->n = 0;
}

void addFirst(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
	L->n++;
}

void add(LinkedListType* L, int pos, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	for (int i = 0; i < pos - 1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link = node;
	L->n++;
}

// void addLast()

// 과제: remove
int remove(LinkedListType *L, int pos)
{
	ListNode* before = L->head;
	if ((pos <= 0) || (pos > L->n))
	{
		printf("invalidRankException...");
		exit(1);
	}
	for (int i = 1; i < pos - 1; i++)
		before = before->link;

	int item;
	if (pos == 1)
	{
		item = before->data;
		L->head = before->link;
	}
	else {
		item = before->link->data;
		before->link = before->link->link;
	}
	L->n--;
	return item;
}

// 과제: remove first
int removeFirst(LinkedListType* L)
{
	ListNode* first = L->head;
	int item = first->data;
	L->head = first->link;
	L->n--;
	return item;
}
// 과제: remove last
int removeLast(LinkedListType *L)
{
	ListNode* before = L->head;
	for (int i = 1; i <= L->n - 2; i++)
		before = before->link;
	int item = before->link->data;
	before->link = NULL;
	L->n--;
	return item;
}

int get(LinkedListType* L, int pos)
{
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	return p->data;
}

void set(LinkedListType* L, int pos, int item)
{
	ListNode* p = L->head;
	for (int i = 1; i < pos; i++)
		p = p->link;
	p->data = item;
}

void printList(LinkedListType* L)
{
	for (ListNode* p = L->head; p != NULL; p = p->link)
		printf("[%d] -> ", p->data);
	printf("NULL\n");
}

int main()
{
	LinkedListType list;
	init(&list);

	addFirst(&list, 10); printList(&list);
	addFirst(&list, 20); printList(&list);
	addFirst(&list, 30); printList(&list);
	getchar();
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);

	int pos;
	printf("\n몇 번 노드의 값을 반환할까요? ");
	scanf("%d", &pos);
	printf("%d번 노드의 값은 %d\n", pos, get(&list, pos));

	printf("\n몇 번 노드를 삭제할까요? ");
	scanf("%d", &pos);
	printf("%d번 노드의 값은 %d 삭제되었습니다.\n", pos, remove(&list, pos)); printList(&list);

	getchar();
	getchar();
	printf("첫번째 노드 삭제\n"); removeFirst(&list); printList(&list);
	getchar();
	printf("마지막 노드 삭제\n"); removeLast(&list); printList(&list);
}
