// Insertion Sort
#include<stdio.h>
void InsertionSort(int A[],int n)
{
    for (int i = 1; i < n; i++) {
        int static pass=1;
        int key = A[i];
        int j = i - 1;
        printf("Pass %d\n",pass);
        pass++;
        printf("%d is Inserted\n",A[i]);
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
        for(int k=0;k<n;k++)
        {
            printf("%d\t",A[k]);
        }
        printf("\n");
    }
}

int main()
{
    int n,A[n];
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the data for the Insertion Sort\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);

    }

    InsertionSort(A,n);
    printf("\nSorted array is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t",A[i]);
    }
    return 0;
}