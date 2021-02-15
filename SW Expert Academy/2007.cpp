#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int t, len;
string input;

int get_repeating_size() {
	for (int size = 2; size <= 10; size++) {
		bool repeating = true;

		// 처음 패턴과 그 다음 패턴(예측)을 비교한다.
		for (int i = 0; i < size; i++) {
			if (input[i] != input[i + size]) {
				repeating = false;
				break; // 다르면 패턴길이 +1
			}
		}
		if (repeating) return size;
	}
	return 1; // 패턴이 2~10이 아니면 1이다.
}

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> input;
		len = input.size();
		int j = 0;
		
		// 앞이랑 뒤 비교(X): ㅋㅋㅋ에잇 간파당함

		// 그럼 패턴을 어떻게 알아낼 수 있지?
		// 방법 1. 정말 하나씩 비교
		for (int k = 1; k < len; k++) {
			// 같은 패턴의 문자가 반복되면 마지막 패턴까지 따라감
			if (input[j] == input[k]) {
				j++;
			}
			// k와 같은 패턴 발견할 때 까지 j는 0으로 감
			else {
				j = 0;
			}
		}
    cout << '#' << i << ' ' << len - j << '\n';
		
		// 방법 2. 사이즈를 예측해서 비교(마디의 최대 길이는 10이라고 하므로)
		int result = get_repeating_size();
		
		cout << '#' << i << ' ' << result << '\n';
	}
}

/*

#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case, result = 0;
	int T;
	bool repeating;

	cin>>T;

    	string input;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        	cin >> input;
        
		for(int size=2; size<=10; size++){
           		repeating = true;
        		for(int i=0; i<size; i++){
				if(input[i] != input[i+size]){
					repeating = false;
					break;
			}
            	 }
		 if(repeating){
		 	result = size;
			break;
            	 }
        }
        	if((repeating==false)) result = 1;
        	cout << '#' << test_case << ' ' << result << '\n';
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
*/
