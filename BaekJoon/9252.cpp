#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
 
#define endl "\n"
#define MAX 1001
using namespace std;
 
string A, B;
int DP[MAX][MAX];
string LCS[MAX][MAX];
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> A >> B;
}
 
void Solution()
{
    int A_Size = A.length();
    int B_Size = B.length();
 
    for (int i = 1; i <= A_Size; i++)
    {
        for (int j = 1; j <= B_Size; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                LCS[i][j] = LCS[i][j] + LCS[i - 1][j - 1] + A[i - 1];
            }
            else
            {
                DP[i][j] = Bigger(DP[i - 1][j], DP[i][j - 1]);
                if (LCS[i - 1][j].length() > LCS[i][j - 1].length())
                {
                    LCS[i][j] = LCS[i - 1][j];
                }
                else
                {
                    LCS[i][j] = LCS[i][j - 1];
                }
            }
 
        }
    }
 
    cout << DP[A_Size][B_Size] << endl << LCS[A_Size][B_Size] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}


출처: https://yabmoons.tistory.com/176 [얍문's Coding World..]
