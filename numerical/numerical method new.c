#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void bisection(double a,double b,double c);
void newton(double a,double b,double c);

int main()
{
    printf("To determine the root of equation\nax^2+bx+c\n");
    double a,b,c;
    printf("Please enter a : ");
    scanf("%lf",&a);
    printf("Please enter b : ");
    scanf("%lf",&b);
    printf("Please enter c : ");
    scanf("%lf",&c);

    int ch1;
    int ch2;
    printf("1.For bracketing method \n2.For open method\nPlease enter your choise :");
    scanf("%d",&ch1);
    if(ch1==1)
    {
        printf("Please enter 11 for bisection method : ");
        scanf("%d",&ch2);
        if(ch2==11)
        {
            bisection(a,b,c);
        }
    }
    if(ch1==2)
    {
        printf("Please enter 21 for newton-rafsan method : ");
        scanf("%d",&ch2);
        if(ch2==21)
        {
            newton(a,b,c);
        }
    }
}

void bisection(double a,double b,double c)
{
    double xu,xl,xr=0,temp,ea,test;

    printf("Please enter Xl : ");
    scanf("%lf",&xl);
    printf("Please enter Xu : ");
    scanf("%lf",&xu);

    int i;
    for(i=0 ; i<100 ; i++)
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

void newton(double a,double b,double c)
{
    double xo,xi,xi_1,ea;
    double fxi,f_xi;
    printf("Please enter X0 :  ");
    scanf("%lf",&xo);
    xi=xo;

    int i;
    for(i=0 ; i<100 ; i++)
    {
        fxi=a*xi*xi+b*xi+c;
        f_xi=2*a*xi+b;
        xi_1=(xi-(fxi/f_xi));
        ea=fabs(((xi_1-xi)/xi_1)*100);

        xi=xi_1;
        if(ea<0.01)
        {
            break;
        }
        printf("Xi : %lf  Ea : %lf\n",xi,ea);
    }
    printf("the root  Xi = %lf ",xi);
}

