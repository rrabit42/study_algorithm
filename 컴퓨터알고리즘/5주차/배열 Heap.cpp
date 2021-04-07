#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 100

typedef struct
{
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h)
{
	h->heap_size = 0;
}

void upHeap(HeapType *h)
{
	int i = h->heap_size;
	int key = h->heap[i];
	
	// root가 아니라면, key 값이 부모보다 크거나 같지 않으면
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];	// 부모 노드 값 아래로 내리기
		i /= 2;							// 노드 타고 올라가기
	}
	h->heap[i] = key;
}

void downHeap(HeapType *h)
{
	int temp = h->heap[1];
	int parent = 1, child = 2;

	while (child <= h->heap_size)
	{
		// child 오른쪽에 노드가 있다는 뜻(<)
		if ((child < h->heap_size) && (h->heap[child] > h->heap[child + 1]))	// 그리고 그 오른쪽 애보다 내가 더 크면
			child++;	// 더 작은애 선택
		
		// child가 마지막 노드가 있고,
		if (temp <= h->heap[child])	// child 값이 나보다 크면 stop
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;		// child도 하나 더 내려가기
	}
	h->heap[parent] = temp;		// 순서 정렬!
}

void insertItem(HeapType *h, int key)
{
	h->heap_size += 1;
	h->heap[h->heap_size] = key;
	upHeap(h);

}

int removeMin(HeapType *h)
{
	int key = h->heap[1];	// root
	h->heap[1] = h->heap[h->heap_size];	// root에 last key값 넣기
	h->heap_size -= 1;		// 마지막 노드 삭제
	downHeap(h);			// 순서 정렬
	return key;
}

void printHeap(HeapType *h)
{
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n");
}

void heapSort(HeapType *h, int list[])
{
	HeapType heap;
	init(&heap);

	for (int i = 1; i <= h->heap_size; i++)
	{
		heap.heap[i] = h->heap[i];
		heap.heap_size++;
	}
	for (int i = 1; i <= h->heap_size; i++)
		list[i] = removeMin(&heap);
}

void printArray(int list[], int n)
{
	for (int i = 1; i <= n; i++)
		printf("[%d] ",list[i]);
	printf("\n");
}

// 제자리 힙정렬
void inPlaceHeapSort(HeapType *h)
{
	int size = h->heap_size;
	int key;
	for (int i = 0; i < size; i++)
	{
		key = removeMin(h);
		h->heap[h->heap_size + 1] = key;
	}
}

int main()
{
	HeapType heap;
	int list[MAX_ELEMENT] = { 0 };
	
	srand(time(NULL));
	init(&heap);
	for (int i = 0; i < 15; i++)
		insertItem(&heap, rand() % 100);
	printHeap(&heap);

	inPlaceHeapSort(&heap);
	for (int i = 1; heap.heap[i] > -1; i++)
		printf("[%d] ", heap.heap[i]);
}
