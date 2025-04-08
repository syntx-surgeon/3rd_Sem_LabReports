#include<stdio.h>
#include<math.h>


float f(float x)
{
    // return x*x*exp(sqrt(x))*sin(x);
    return cos(x) * exp(-x) + x;
}


int main()
{

    float a,h,fd1,fd2;
    char q;
    do{
        printf("Enter the point at which derivatives are required: ");
        scanf("%f",&a);
        printf("Enter the value of h: ");
        scanf("%f",&h);
        fd1=(f(a+h)-f(a-h))/(2*h);
        fd2=(f(a+h)-2*f(a)+f(a+h))/(h*h);
        printf("The first and second derivatives at x=%f are\t %f and \t%f respectively.",a,fd1,fd2);
        printf("Do you want to input another values?(y/n):");
        scanf("%s",&q);
    }

    while (q=='y');
    return 0;
}