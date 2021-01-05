#include <cstdio>
#include <cmath>

using namespace std;

int main () {

    int n, n2, i, j, cnt ;
    bool arr[246913];

    while(1) {
        scanf("%d", &n);
        if (n == 0) break;
        cnt = 0;
        n2 = n * 2;

        for (i = 2; i <= n2; i++) arr[i] = true;

        for (i = 2; i <= sqrt(n2); i++) {
            if (arr[i]) {
                for (j = i+i; j <= n2; j += i) {
                    if (arr[j]) {
                        arr[j] = false;
                    }
                }
            }
        }

        for (i = n + 1; i <= n2; i++) {
            if (arr[i]) cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
