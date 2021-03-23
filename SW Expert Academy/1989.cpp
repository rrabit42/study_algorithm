#include<iostream>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
    string word;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> word;
		int result = 1;
		int length = word.length();
		int idx = (length % 2 == 0) ? (length / 2 - 1) : (length / 2);
		
		for (int start = 0; start <= idx; start++) {
			if (word[start] != word[length - 1 - start]) {
				result = 0;
				break;
			}
		}
		
		printf("#%d %d\n", test_case, result);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
