// 또 프로그래머스에서만 segmentation fault (core dumped) 발생...
// 그래서 2, 3단계를
/*
// 2 단계 
    for(int i = 0; i < id.length(); ) {
        if ((id[i] >= 'a' && id[i] <= 'z') || (id[i] >= '0' && id[i] <= '9') || id[i] == '-' || id[i] == '_' || id[i] == '.')
        {
            i++;
            continue;
        }
        
        id.erase(id.begin() + i);
    }
    
    // 3 단계
    for(int i = 0; i < id.length()-1; ){
        if (id[i] == '.' && id[i + 1] == '.'){
            id.erase(id.begin() + i);
            continue;
        }
        else i++;
    }
*/
// 이렇게 바꿔주니 통과
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

string id, answer;
vector<char> v;
string special = "-_.~!@#$%^&*()=+[{]}:?,<>/";

void input() {
	cin >> id;
}

string solution(string id) {
	// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
	//transform(id.begin(), id.end(), id.begin(), tolower);
	// transform이 아무리 해도 import가 안돼서 바꿔줌
	for(int i = 0; i < id.length(); i++)
		if (id[i] >= 'A' && id[i] <= 'Z')
			id[i] = tolower(id[i]);
	
	char ch;
	// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
	for (int i = 0; i < id.length() - 1;) {
		ch = id[i];
		// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
		if ((isalpha(ch) == 2) || isdigit(ch) || ch == '-' || ch == '_' || (ch == '.' && id[i + 1] != '.')) {
			i++; // 지워지면 index 자동 증가 효과가 나기 때문에 erase 안할 때만 +1
			continue;
		}
		id.erase(id.begin() + i);
	}

	// 범위 때문에 마지막 원소는 따로 검사!
	int n = id.length();
	ch = id[n];
	if ((isalpha(ch) != 2) && !isdigit(ch) && ch != '-' && ch != '_' && ch != '.') {
		id.erase(id.begin() + n);
	}

	// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
	if (id.front() == '.') {
		id.erase(id.begin());
	}
	if (id.back() == '.') {
		id.erase(id.end() - 1);
	}

	// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
	if (id.length() == 0) {
		id = "a";
	}

	// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	while (id.length() >= 16) {
		id.erase(id.begin() + 15);
	}

	// 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
	if (id.back() == '.') {
		id.erase(id.end() - 1);
	}

	// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
	while (id.length() < 3) {
		id += id.back();
	}

	return id;
}

int main() {
	input();
	answer = solution(id);

	cout << answer;
}

/*
// 이상하게 visual studio에서는 잘 돌아가는데 프로그래머스에서는 이상하게 output이 나옴.... 왜그래...

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

string id, answer;
vector<char> v;
string special = "-_.~!@#$%^&*()=+[{]}:?,<>/";

/*
1. 단항 함수형 transform
	OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op);
	- first1, last1 : transform 함수를 적용할 원소들을 가리키는 범위
	- d_first : 결과를 저장할 범위. (first1과 동일해도 됨. 이 경우, 기존 데이터를 덮어쓰게 됨)
	- unary_op : 원소들을 변환할 함수
	=> "first1부터 last1 전까지 범위의 원소들을 unary_op를 수행하고, 그 결과를 d_first부터 차례로 저장한다"

2. 이항함수형 transform
	OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op);
	- first1, last1 : transform 함수를 적용할 첫 번째 원소들을 가리키는 범위
	- first2 : transform 함수를 적용할 두 번째 원소들의 시작점
	- d_first : 결과를 저장할 범위. (first1, first2와 동일해도 됨. 이 경우, 기존 데이터를 덮어쓰게 됨)
	- binary_op : 원소들을 변환할 함수. 2 개의 parameter를 가짐.
	=> "first1부터 last1 전까지 범위의 원소들과 first2부터 동일 갯수의 원소들로 binary_op를 수행하고, 그 결과를 d_first부터 차례로 저장한다"

*/
void input() {
	cin >> id;
}

string solution(string id) {
	// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
	// transform(id.begin(), id.end(), id.begin(), tolower);
	for (int i = 0; i < id.length(); i++) {
		if (isalpha(id[i]) == 1)
			id[i] = tolower(id[i]);
	}

	int n = id.length();
	// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
	for (int i = 0; i < n - 1; i++) {
		char ch = id[i];
		if ((isalpha(ch) == 2) || isdigit(ch) || ch == '-' || ch == '_' || (ch == '.' && id[i + 1] != '.')) {
			v.push_back(ch);
		}
	}

	n = v.size();
	char ch = id[n];
	if ((isalpha(ch) == 2) || isdigit(ch) || ch == '-' || ch == '_' || ch == '.') {
		v.push_back(ch);
	}

	n = v.size();
	// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
	if (v.front() == '.') {
		v.erase(v.begin());
	}
	if (v.back() == '.') {
		v.pop_back();
	}

	// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
	if (v.empty()) {
		v.push_back('a');
	}

	n = v.size();
	// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	while (n >= 16) {
		v.pop_back();
		n--;
	}

	// 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
	if (v.back() == '.') {
		v.pop_back();
	}

	n = v.size();
	// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
	while (n < 3) {
		char ch = v.back();
		v.push_back(ch);
		n++;
	}

	n = v.size();
	// string 으로 옮겨 담기(오류)
	for (int i = 0; i < n; i++) {
		answer += v[i];
	}

	return answer;
}

int main() {
	input();
	answer = solution(id);

	cout << answer;
}
*/
