#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX 100002

/*
	분할정복
	1. 스택 사용: O(N)
	2. 세그먼트 트리 사용 O(NlgN)
		(0,N-1) 범위에서의 최소 높이를 갖는 인덱스를 저장
		이 인덱스를 통해 높이를 구하고 가로 길이를 곱해서 직사각형의 넓이구하고,
		이 인덱스를 기준으로 다시 좌, 우로 나눠 다시 넓이를 구하는 식으로 모든 가능한 직사각형의 넓이 구하기
*/


int main() {
	// input size가 10억까지 주어지기 때문에 long으로 선언!
	long x;
	long y[MAX] = { 0, };
	long width, height, area = 0;
	stack<int> st;

	// 입력값 받기
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> y[i];
	}

	// 직사각형이 결정되는 순간은 이전의 막대 높이보다 현재의 막대 높이가 더 낮을 때!
	// 즉, stack의 top이 직사각형의 왼쪽 끝, i가 오른쪽 끝
	// But, index 0 부터 시작하면 맨 왼쪽 끝이 마지막 width에 포함이 안되는 반례가 발생한다!!(pop이 되어 index 0이 꺼내질 수도 있기 때문!)
	// 그래서 양쪽에 여분 index를 하나씩 놔두는게 좋다. 그게 0과 x+1이 되는 것이다!
	// 즉, 양쪽 사이드에 0을 넣어놓는 것!
	st.push(0);
	for (int i = 1; i <= x + 1; i++) {
		while (!st.empty() && y[st.top()] > y[i])
		{
			height = y[st.top()];
			st.pop();
			width = i - st.top() - 1; // pop 한 후에 width에서 빼는 거니까 -1 해줘야 원래 width가 맞음
			/*
				width = i - st.top();
				st.pop();
				
				이렇게 하면 안되나?
				왜냐하면 stack에 0과 N-1 을 제외하고 모두 없앤 후 마지막으로 (최소높이)*N을 계산하려고!
			*/

			area = max(area, height*width);
		}
		st.push(i);
	}

	cout << area;
	return 0;
}
