#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{

    printf("enter xl,xu,a,b,c : \n");
    double xu,xl,xr=0,temp,ea,test,ex;
    double a,b,c;
    scanf("%lf",&xl);
    scanf("%lf",&xu);
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    int i;
    for(i=0 ; i<10 ; i++)
    {
        temp=xr;
        xr=(xl+xu)/2;
        test=(a*xl*xl+b*xl+c)*(a*xr*xr+b*xr+c);
        if(test<0)
        {
            xu=xr;
        }
        else if (test>0)
        {
            xl=xr;
        }
        else
        {
            xr=xl;
        }

        ea=fabs(((xr-temp)/xr)*100);


       if(ea<0.1)
        {
            break;
        }
         printf("XR:%f EA:%f\n",xr,ea);
    }

    printf("THE ROOT IS APPROXIMATELY : %lf",xr);

}

