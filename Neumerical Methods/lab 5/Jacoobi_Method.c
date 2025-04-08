#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPS 0.0001

int main() {
    int i, j, n, key, count = 0;
    float a[MAX][MAX], b[MAX], x[MAX], xold[MAX], sum;
    printf("\nInput number of variables: ");
    scanf("%d", &n);

    printf("\nInput coefficients row-wise:\n");
    for (i = 1; i <= n; i++) {\
        0
        
        for (j = 1; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nEnter vector b: ");
    for (i = 1; i <= n; i++) {
        scanf("%f", &b[i]);
    }

    for (i = 1; i <= n; i++) {
        xold[i] = 0; // Initial guess
    }

    do {
        key = 0;
        for (i = 1; i <= n; i++) {
            sum = b[i];
            for (j = 1; j <= n; j++) {
                if (j != i) {
                    sum = sum - (a[i][j] * xold[j]);
                }
            }
            x[i] = sum / a[i][i];
            if ((key == 0) && (fabs(x[i] - xold[i]) / x[i] > EPS)) {
                key = 1;
            }
        }
        for (i = 1; i <= n; i++) {
            xold[i] = x[i];
        }
        count++;
    } while (key == 1);

    printf("\nSolution vector x:\n");
    for (i = 1; i <= n; i++) {
        printf("\t%f", x[i]);
    }
    printf("\nNumber of iterations: %d\n", count);

    return 0;
}