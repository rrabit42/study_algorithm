#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 10

using namespace std;

int t, n;
int triangle[MAX][MAX] = {0, };

int dfs(int row, int col, int n) {
	int &result = triangle[row][col];

	// 두번째 입력은 여기서 바로 return 되어 나가는 문제 발생
	if (result != 0) return result;

	// 범위 체크
	if (row >= 0 && row < n && col >= 0 && col < n) {
		if (col == 0 || row == col) {
			// 맨 양 끝은 1
			result = 1;
		}
		else {
			// 나머지는 계산
			result = dfs(row - 1, col - 1, n) + dfs(row - 1, col, n);
		}

		// 그 다음으로 움직이기
		if (col < row) {
			dfs(row, ++col, n);
		}
		else if (row < n) {
			dfs(++row, 0, n);
		}
	}
}

int main() {
	cin >> t;
	
	// 그래서 걍 미리 채워주고 시작ㅎㅎ
	dfs(0, 0, 10);

	for (int test_case = 1; test_case <= t; test_case++) {
		cin >> n;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= j; k++) {
				cout << triangle[j][k]<< ' ';
			}
			cout << '\n';
		}
	}
}

/*
#include <iostream>

using namespace std;

int main(void)
{
    int t;
    int arr[10][10];
    arr[0][0] = 1;
    
    cin >> t;
    
    // ** 하긴 미리 돌릴거면 재귀 할 필요도 없겠다..ㅋㅋ 걍 채워줄 듯
    for(int i = 1; i < 10; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    
    for(int i = 1; i < t; i++)
    {
        int n;
        cin >> n;
        
        cout << "#" << i << endl;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k <= j; k++)
                cout << arr[j][k] << " ";
            cout << endl;
        }
    }
    return 0;
}
*/
