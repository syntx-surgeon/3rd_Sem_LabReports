//BInary Search
#include<stdio.h>
#include<math.h>
void BinarySearch(int A[], int l, int r, int key) 
{
    if(l <= r) 
    {
        int mid = (l + r) / 2;
        if(A[mid] == key)
        {
            printf("Search is found at index %d\n", mid);
            return;
        }
        else if(A[mid] > key)
        {
            BinarySearch(A, l, mid - 1, key);
        }
        else 
        {
            BinarySearch(A, mid + 1, r, key);
        }
    }
    else
    {
        printf("Search is not found\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int A[n]; 
    printf("Input the data either in ascending or descending order\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int key; 
    printf("Enter the element to search for: ");
    scanf("%d", &key);
    BinarySearch(A, 0, n-1, key); 
    return 0;
}