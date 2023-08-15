#include<stdio.h>
int main()
{
    printf("enter xu,xl,a,b,c : \n");
    float xu,xl,xr=0,temp,ea,test;
    float a,b,c;
    scanf("%f \n",&xl);
    scanf("%f \n",&xu);
    scanf("%f \n",&a);
    scanf("%f \n",&b);
    scanf("%f \n",&c);
//ea=10000;
   do
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

            ea=1-((temp*100)/xr);
            printf("XR:%f EA:%f\n",xr,ea);
        } while(ea>=0);

return 0;

}

