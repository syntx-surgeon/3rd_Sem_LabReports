//Bubble Sort
#include<stdio.h>
void BubbleSort(int A[],int n)
{
    int static pass=1;
    for(int i=0;i<n-1;i++)
    {   
        printf("Pass %d\n",pass);
        pass++;
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp;
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
            for(int k=0;k<n;k++)
            {
                printf("%d\t",A[k]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int n;
    int A[n];
    printf("Enter the size of Array:\n");
    scanf("%d",&n);
    printf("Enter the data for the Bubble Sort:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    BubbleSort(A,n);
    printf("\nSorted Array is: ");
    for (int i = 0; i <n; i++)
    {
        printf("%d\t",A[i]);
    }
    return 0;
}
