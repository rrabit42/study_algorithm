#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

typedef struct
{
	int num;
	float s, e;
}Segment;

typedef struct
{
	float coor;
	char code;
	int id;
}Event;

typedef struct
{
	int id1, id2;
}interSegment;

// 좌표로 정렬
void insertion_sort(Event ev[], int n)
{
	int i, j;
	Event item;
	for (i = 1; i < n; i++)
	{
		item = ev[i];
		for (j = i - 1; j >= 0 && ev[j].coor > item.coor; j--)
			ev[j + 1] = ev[j];
		ev[j + 1] = item;
	}
}

void findIntersectingSegment(Event ev[])
{
	int openSegments[SIZE];
	interSegment is[SIZE * 2];
	int oCnt = 0;	// open 개수
	int iCnt = 0;	// inter 개수

	for (int i = 0; i < SIZE * 2; i++)
	{
		if (ev[i].code == 'S')
		{
			for(int j=0; j<oCnt; j++)
				if (openSegments[j] != 0)
				{
					// inter집합에 넣기
					is[iCnt].id1 = openSegments[j];
					is[iCnt].id2 = ev[i].id;
					iCnt++;
				}
			// open집합에 넣기
			openSegments[oCnt++] = ev[i].id;
		}
		else
		{
			for (int j = 0; j < oCnt; j++)
				if (openSegments[j] == ev[i].id)
					openSegments[j] = 0;
		}
	}

	for (int i = 0; i < iCnt; i++)
		printf("(%d, %d) ", is[i].id1, is[i].id2);
	printf("\n");
}

int main()
{
	Segment lines[] = {
		{1, 1.0, 3.2},
		{2, 0.8, 3.0},
		{3, 0.6, 2.8},
		{4, 1.1, 2.0},
		{5, 5.4, 7.0},
		{6, 2.9, 5.0}
	};
	Event ev[SIZE * 2];
	for (int i = 0; i < SIZE; i++)
		printf("%d, (%.1f ~ %.1f)\n", lines[i].num, lines[i].s, lines[i].e);
	printf("\n");

	getchar();

	for (int i = 0, j = 0; i < SIZE * 2; i++, j++)
	{
		// 한 line마다 이벤트 2개 필요
		ev[i].coor = lines[j].s;
		ev[i].code = 'S';
		ev[i].id = lines[j].num;

		ev[i + 1].coor = lines[j].e;
		ev[i + 1].code = 'E';
		ev[++i].id = lines[j].num;	// 따라서 여기서 +1, 그리고 조건문 +1 해서 +2시키는것!
	}
	for (int i = 0; i < SIZE * 2; i++)
		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
	printf("\n");

	getchar();

	// 정렬
	insertion_sort(ev, SIZE * 2);
	for (int i = 0; i < SIZE * 2; i++)
		printf("((%.1f, %c), %d)\n", ev[i].coor, ev[i].code, ev[i].id);
	printf("\n");

	// openSegments: start한 선분들
	// openSegments 에 있는 애들을 돌면서 교차한 선분 interSegment에 넣기
	// 왜냐하면 열려있는 애들은 다 교차하는 거니까
	// 그리고 E event가 들어오면 openSegment에 있는 애를 닫아줌
	// 집합이라 중복된 원소는 지워줘야함

	findIntersectingSegment(ev);

	return 0;
}
