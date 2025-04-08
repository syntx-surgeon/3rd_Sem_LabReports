#include <stdio.h>
#include <math.h>
#include <conio.h>

float f(float x)
{
	//	return 1.0-exp(-x/2.0);
	// return (exp(x)) / x;
	return (1.0 / (1 + x * x));
}

int main()
{
	int n, m, i;

	float a, b, h, sum = 0.0, ics, x;
	printf("Give a lower limit of intergration a:\n");
	scanf("%f", &a);
	printf("Give a upper limit of integration b:\n");
	scanf("%f", &b);
	do
	{
		printf("Give number of segements n(Even number):\n");
		scanf("%d", &n);
	} while (n % 2 != 0);
	h = (b - a) / n;
	m = n / 2;
	for (i = 1; i <= m; i++)
	{
		x = a + (2 * i - 1) * h;
		sum = sum + 4 * f(x);
		if (i != m)
		{
			sum = sum + 2 * f(x + h);
		}
	}
	sum = sum + f(a) + f(b);
	ics = sum * h / 3.0;
	printf("Integration between %f and %f when h=%f is %f:\n", a, b, h, ics);
	getch();
	return 0;
}
