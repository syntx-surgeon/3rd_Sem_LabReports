//Newton Interpolation Forward Difference Formula


#include<stdio.h>
#include<math.h>
#define MAX 15
int main()
{
   float x[MAX],fx[MAX],fd[MAX],xp,s,h,v,p;
   int n,i,j;
   char q;
   printf("Input the number of data pairs:");
   scanf("%d",&n);
   printf("\nInput data pairs: \n");
printf("For x(i):\n");
for(i=0;i<n;i++){
   scanf("%f",&x[i]);
}
printf("For fx(i):\n");
for(i=0;i<n;i++){
   scanf("%f",&fx[i]);
}
   h=x[2]-x[1];
   do{
       printf("Enter the value at which interpolation is required:");
       scanf("%d",&xp);
       s=(xp-x[1]/h);
       p=1;
       v=fx[1];
       for(i=1;i<=n;i++){
           for(j=1;j<=n;j++){
               fd[j]=fd[j+1]-fd[j];
           }
           p=p*(s-i+1)/i;
           v=v+p*fd[1];
       }
       printf("Interpolated function value at x=%f is %f.",xp,v);
       printf("\nDo you want to input another value?(y/n):");
       scanf("%c",&q);

   }while(q=='y');
   return 0;
}