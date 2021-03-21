#include <stdio.h>
#include <stdlib.h>

#define N 7
#define K 3

typedef struct ListNode
{
	int elem;
	struct ListNode* next;
}ListNode;

// 노드 생성
ListNode* getnode()
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	return p;
}

// 배열 초기화
ListNode* buildList(int n)
{
	ListNode *p = getnode();
	ListNode *L = p;

	// elem 초기화
	p->elem = 1;
	for (int i = 2; i <= n; i++)
	{
		p->next = getnode();
		p = p->next;
		p->elem = i;
	}

	// 원형 만들기
	p->next = L;

	return L;
}


// 원형연결리스트
int runSimulation(ListNode *L, int n, int k)
{
	ListNode *p = L;
	
	// 양초가 1개 이상일 때
	while (p != p->next)
	{
		// k 간격만큼 이동
		for (int i = 1; i < k; i++)
		{
			p = p->next;
		}
		
		ListNode *pnext = p->next;

		// 양초 끄기
		p->next = (p->next)->next;

		// 다음 양초로 가기
		p = p->next;
	}
	return p->elem;
}

// 양초 불기
int candle(int n, int k)
{
	ListNode* L = buildList(n);
	return runSimulation(L, n, k);
}

int main()
{
	int A[N] = { 0, };

	printf("특수 양초의 위치는 %d번 입니다.\n", candle(N, K));
}
