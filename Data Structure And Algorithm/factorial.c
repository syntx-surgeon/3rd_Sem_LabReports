//factorial
#include<stdio.h>
#include<conio.h>

int fact(int n)
{
	if(n==0 || n==1)
	return 1;
	else
	return (n*fact(n-1));
	
}


int main()
{
	int m;
	int facto;
	printf(
	"Enter the number \n");
	scanf("%d",&m);
	facto=fact(m);
	printf("Pogram Factorial\n");
	printf("Compiled By Bhim Raj Bhandari\n");
	printf("The factorial of %d is %d \n",m,facto);
	return 0;

}
