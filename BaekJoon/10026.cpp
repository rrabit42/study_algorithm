#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
 
using namespace std;
int count1 = 0, count2 = 0, n;
 
void DFS(int **arr, int num, int x, int y) {
    arr[y][x] = 0;
    if (y > 0 && arr[y - 1][x] == num)
        DFS(arr, num, x, y - 1);
    if (y < n - 1 && arr[y + 1][x] == num)
        DFS(arr, num, x, y + 1);
    if (x > 0 && arr[y][x - 1] == num)
        DFS(arr, num, x - 1, y);
    if (x < n - 1 && arr[y][x + 1] == num)
        DFS(arr, num, x + 1, y);
}
 
int main() {
    string str;
    cin >> n;
    int **arr1 = new int*[n], **arr2 = new int*[n];
 
    for (int i = 0; i < n; i++) {
        arr1[i] = new int[n];
        arr2[i] = new int[n];
    }
 
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            switch (str[j])
            {
            case 'R':
                arr1[i][j] = 1;
                arr2[i][j] = 1;
                break;
            case 'G':
                arr1[i][j] = 2;
                arr2[i][j] = 1;
                break;
            case 'B':
                arr1[i][j] = 3;
                arr2[i][j] = 2;
                break;
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr1[i][j] != 0) {
                count1++;
                DFS(arr1, arr1[i][j], j, i);
            }
            if (arr2[i][j] != 0) {
                count2++;
                DFS(arr2, arr2[i][j], j, i);
            }
        }
    }
    cout << count1 << " " << count2;
    return 0;
}
