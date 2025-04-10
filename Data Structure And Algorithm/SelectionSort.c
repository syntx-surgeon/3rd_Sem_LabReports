//Selection Sort

#include<stdio.h>
void swap(int*a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
 void SelectionSort(int A[],int n)
 {
        for(int i=0;i<n;i++)
        {
           
           int least=A[i];
           int p=i;
           int static pass=1;
           printf("Pass %d\n",pass);
           pass++;
            for(int j=0;j<n;j++)
            {
                if(A[j]<A[p])
                {
                    least=A[j];
                    p=j;

                
                for (int k = 0; k <n; k++)
                {
                    printf("%d\t",A[k]);
                }
                printf("\n");
                
            }
            swap(&A[i],&A[p]);
        }
 }
 }
 int main()
 {
    int n,A[n];
    printf("Enter the Size of Array\n");
    scanf("%d",&n);
    printf("Enter the data for the Selection Sort");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    SelectionSort(A,n);
    printf("\nSorted Array is: ");
    for (int  i = 0; i < n; i++)
    {
    printf("%d\t",A[i]);
    }
    return 0;
 }