#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPS 0.0001

int main() {
    int i, j, k, n, count = 0;
    float ev = 1.0, ev_temp, temp_max, a[MAX][MAX], x[MAX], y[MAX];
    printf("\nInput size of matrix: ");
    scanf("%d", &n);
    printf("\nInput elements row-wise:\n");

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    for (i = 1; i <= n; i++)
        x[i] = 1; // Initial guess for eigenvector

    do {
        for (i = 1; i <= n; i++)
            y[i] = 0; // Reset y vector

        ev_temp = ev;

        // Matrix-vector multiplication
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                y[i] += a[i][j] * x[j];

        // Update x with the result
        for (i = 1; i <= n; i++)
            x[i] = y[i];

        // Find the maximum element in x
        temp_max = fabs(x[1]);
        k = 1;

        for (j = 2; j <= n; j++) {
            if (fabs(x[j]) > temp_max) {
                temp_max = fabs(x[j]);
                k = j;
            }
        }

        ev = x[k]; // Update eigenvalue

        // Normalize the eigenvector
        for (i = 1; i <= n; i++)
            x[i] = x[i] / ev; 

        count++;

    } while (fabs((ev_temp - ev) / ev) > EPS);

    printf("\nApproximate eigenvalue is %f\n", ev);
    printf("Corresponding eigenvector is:\n");
    for (i = 1; i <= n; i++)
        printf("\t%f", x[i]);

    printf("\nNumber of iterations: %d\n", count);

    return 0;
}