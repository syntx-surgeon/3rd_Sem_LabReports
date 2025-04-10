//Fibonacci
#include<stdio.h>
#include<conio.h>

int fibo(int n)
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else 
	return (fibo(n-1)+fibo(n-2));
	
}


int main()
{
	int m,it;
	printf("Pogram Fibonacci\n");
	printf("Compiled By Bhim Raj Bhandari\n");
	printf("Enter the number\n");
	scanf("%d",&m);
for(int i=0; i<=m;i++)
{
	printf("%d ,",fibo(i));
}

	return 0;
}



