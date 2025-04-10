// GCD

#include <stdio.h>
#include <conio.h>

int gcd(int a, int b)
{

	if (b == 0)
		return a;
	else
		return (gcd(b, a % b));
}

int main()
{
	int x, y, res;
	printf("Enter the two number \n");

	scanf("%d%d", &x, &y);

	res = gcd(x, y);
	printf("Pogram GCD\n");
	printf("Compiled By Bhim Raj Bhandari\n");
	printf("The gcd of given two number %d and %d is %d", x, y, res);
	return 0;
}
