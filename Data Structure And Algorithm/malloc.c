// malloc
#include <stdio.h>
#include <stdlib.h>
int main()
{
   int i, n, *ptr;
   int sum = 0;
   printf("Enter the number\n");
   scanf("%d", &n);
   ptr = (int *)malloc(n * sizeof(int));

   printf("Before Initialzing\n\n\n");
   for (i = 0; i < n; i++)
   {
      printf("%d\n\n", *(ptr + i));
   }

   printf("After initialization\n\n");
   for (i = 0; i < n; i++)
   {
      scanf("%d", ptr + i);
      sum = sum + *ptr + i;
   }
   printf("Pogram Malloc\n");
   printf("The value of sum is %d\n", sum);
   printf("Compiled By Bhim Raj Bhandari\n");
   free(ptr);
   return 0;
}