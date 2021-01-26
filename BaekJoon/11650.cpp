#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

// C++ sort 함수 활용법 숙지
/*
	sort(start, end)
	
	- intro sort로 구현(quicksort에 heapsort와 insertion sort를 섞음)
	- 평균이어도 최악이어도 nlogn 보장

	- [start,end)의 범위의 있는 인자를 compare 함수를 이용하여 정렬
	- compare overwrite 안하면 default로 오름차순 정렬, compare()이 아닌 compare로 넣어줘야한다.
	- compare는 bool형 함수나 수식을 넣어줄 수 있음
	  함수를 사용하는 경우, 두 개의 매개 변수를 받도록 선언하면 sort에서 자동으로 값 할당
	
	- compare의 기본 작동방식
		bool compare(int i, int j){return i < j;}
		
		자동으로 start 위치가 i에, end 위치가 j로 들어간다.
		그래서 default가 오름차순인 것.
  
  - compare 함수는 strict weak ordering 을 만족하게 작성해야한다.
    비반사성(irreflexivity): 모든 x에 대해 R(x, x)는 거짓
    비대칭성(asymmetry): 모든 x, y에 대해 R(x, y)가 참이면 R(y, x)는 거짓
    추이성(transitivity): 모든 x, y, z에 대해 R(x, y)와 R(y, z)가 참이면 R(x, z)는 참
    비비교성의 추이성(transitivity of incomparability): 모든 x, y, z에 대해 R(x, y)와 R(y, x)가 거짓이고 R(y, z)와 R(z, y)가 거짓이면 R(x, z)와 R(z, x)는 거짓
  - 간단하게 말하면, return 값이 true가 나오면 바꾸고, false면 그대로 간다.
    즉 위에서는 큰수를 두번째 인자(뒤에)로 나오게 해라 -> 오름차순
   
  - 더욱 간단하게, 정렬이 일어나는 방향으로 true가 나오게 하면 됨!!!!! ex. 오름차순 정렬 -> 두번째 인자가 true여야 하니까 i<j

*/

bool compare(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) {
		return a.second < b.second; // y좌표를 오름차순으로
	}

	return a.first < b.first; // x가 같지 않다면, x좌표를 오름차순으로
}

int main() {
	// 시간초과가 계속 나서 추가함
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	
	vector<pair<int, int>> v(num);

	//v로 선언 후 v.resize(N) 해줘도 됨.

	for (int i = 0; i < num; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < num; i++) {
		cout << v[i].first << ' ' << v[i].second << "\n";
	}
}
