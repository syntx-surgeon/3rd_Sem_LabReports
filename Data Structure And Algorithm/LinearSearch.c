#include<stdio.h>
void LinearSearch(int A[],int key,int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        printf("Checking index %d: %d\n", i, A[i]);
        if(key==A[i])
        {   printf("Element is found at index %d\n",i);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("Search is not found");
    }

}

int main()
{
    int n,A[n],key;
    printf("Enter the size of data\n");
    scanf("%d",&n);
    printf("Input the data in Sorted order either in ascending or descending order\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    printf("Enter the Key to be searched\n");
    scanf("%d",&key);
    LinearSearch(A,key,n);
    return 0;

}

