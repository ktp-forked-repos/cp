#include <stdio.h>
#include <stdlib.h>

struct cell {
    int up;
    int left;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int n, m;
    int i, j;
    scanf("%d %d", &n, &m);
    while (n != 0 && m != 0) {
        struct cell a[n][m];
        int top[n][m];
        int left[n][m];
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &(a[i][j].up));
                printf("%d\t", a[i][j].up);
            }
            printf("\n");
        }
        printf("\n");
        int sum;
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < m; j++) {
                scanf("%d", &(a[i][j].left));
                sum += a[i][j].left;
                left[i][j] = sum;
                printf("%d\t", a[i][j].left);
            }
            printf("\n");
        }
        printf("\n");
        for (j = 0; j < m; j++) {
            sum = 0;
            for (i = 0; i < n; i++) {
                sum += a[i][j].up;
                top[i][j] = sum;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%d\t", top[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%d\t", left[i][j]);
            }
            printf("\n");
        }
        int dp[n][m];
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = max(top[i][j], left[i][j]);
                else if (i == 0)
                    dp[i][j] = max(top[i][j] + dp[i][j-1], left[i][j]);
                else if (j == 0)
                    dp[i][j] = max(left[i][j] + dp[i-1][j], top[i][j]);
                else
                    dp[i][j] = max(left[i][j] + dp[i-1][j], top[i][j] + dp[i][j-1]);
            }
        }
        printf("\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%d\t", dp[i][j]);
            }
            printf("\n");
        }
        printf("%d\n", dp[n-1][m-1]);
        scanf("%d %d", &n, &m);
    }
}


