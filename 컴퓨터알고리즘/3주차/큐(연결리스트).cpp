#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
	int data;
	struct QueueNode* link;
}QueueNode;

typedef struct
{
	QueueNode* front;
	QueueNode* rear;
}LinkedQueue;

void init(LinkedQueue* queue)
{
	queue->front = queue->rear = NULL;
}

int is_empty(LinkedQueue* queue)
{
	return queue->front == NULL;
}

void enqueue(LinkedQueue* queue, int data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;		// queue의 마지막에 삽입되니까
	if (is_empty(queue))	// 내가 첫번째 노드일 때
	{
		queue->front = temp;
		queue->rear = temp;
	}
	else
	{
		queue->rear->link = temp;
		queue->rear = temp;
	}
}

int dequeue(LinkedQueue* queue)
{
	QueueNode* temp = queue->front;
	int data;
	if (is_empty(queue))
	{
		fprintf(stderr, "Queue is empty\n");
		exit(1);
	}
	else
	{
		data = temp->data;			// 삭제되어야 할 값
		queue->front = temp->link;	// 뒤에 애들은 계속 이어줘야지
		if (queue->front == NULL)	// 전체 연결된 노드가 1개 밖에 없었음
			queue->rear = NULL;		// 그럼 이제 빈 queue니까 temp 가리키던 rear도 NULL로 초기화
		free(temp);
		return data;
	}
}

void print_queue(LinkedQueue* queue)
{
	QueueNode* p;
	for (p = queue->front; p != NULL; p = p->link)
		printf("|%d| ->", p->data);
	printf("|NULL|\n");
}

int main()
{
	LinkedQueue queue;
	init(&queue);

	enqueue(&queue, 10); print_queue(&queue);
	enqueue(&queue, 20); print_queue(&queue);
	enqueue(&queue, 30); print_queue(&queue);
	getchar();
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
}
