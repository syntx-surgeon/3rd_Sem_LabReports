// Tail recursion of sum of numbers from 1 to n
#include <stdio.h>

int sum_tail(int n, int sum) {
    if (n <= 0) {
        return sum;
    }
    
    return sum_tail(n - 1, sum + n);
}

int sum(int n) {
    return sum_tail(n, 0);
}

int main() {
    int number;
    

    printf("Enter a positive number: ");
    scanf("%d", &number);
    
    int result = sum(number);
    printf("Sum of numbers from 1 to %d = %d\n", number, result);
    
    return 0;
}