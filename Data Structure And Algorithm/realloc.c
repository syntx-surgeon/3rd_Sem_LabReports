// calloc

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, n1, *ptr;
    int sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation is failed
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

    printf("The value of sum is %d\n", sum);

    // ask to the user for new data

    printf("Enter the new data\n");
    scanf("%d", &n1);
    printf("Enter the %d data\n\n", n1);

    ptr = (int *)realloc(ptr, n1 * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Allocation is failed\n");
        return 1;
    }

    // After reallocating

    sum = 0;

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", ptr + i);
        sum = sum + *ptr + 1;
    }

    printf("Pogram Realloc\n");
    printf("After Allocating the new size %d\n", sum);
    printf("Compiled By Bhim Raj Bhandari\n");
    // Free the allocated memory
    free(ptr);

    return 0;
}
