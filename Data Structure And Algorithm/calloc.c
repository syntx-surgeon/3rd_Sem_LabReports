// calloc

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, *ptr;
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Before Initializing:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", *(ptr + i)); // This will print 0 for all elements
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i); // Read integers into the allocated memory
    }
    printf("Pogram Calloc\n");
    printf("The value of sum is %d\n", sum);
    printf("Pogram Calloc\n");
    printf("Compiled By Bhim Raj Bhandari\n");
    // Free the allocated memory
    free(ptr);

    return 0;
}
