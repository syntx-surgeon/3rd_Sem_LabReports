// Tower of hanoi

#include<stdio.h>
#include<conio.h>

int TOH(int n,char a,char b,char c)
{
    
	if(n>0)
	{
		TOH(n-1,a,c,b);
		printf("Move disk %d %c to %c\n",n,a,c);
		
		TOH(n-1,b,a,c);
	}
}

int main()
{
	int n;
	char a='X';
	char b='Y';
	char c='Z';
	printf("Enter the no of disk\n");
	scanf("%d",&n);
	printf("Pogram TOH\n");
	printf("Compiled By Bhim Raj Bhandari\n");
	TOH(n,a,b,c);
	return 0;
}
