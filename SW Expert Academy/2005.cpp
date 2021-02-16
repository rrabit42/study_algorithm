#include <iostream>

using namespace std;

int main(void)
{
    int t;
    int arr[10][10];
    arr[0][0] = 1;
    
    cin >> t;
    
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
