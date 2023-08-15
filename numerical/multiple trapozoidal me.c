#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<math.h>
float valuey(float a,float b,float c,float x);
int main()
{
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(BLUE);


    int n,i;
    float xl,xu,h,x[10],y[10],a,b,c,sum,inti,ea;
    printf("DETERMINE INTIGRATION OF 'ax^2+bx+c'\n");
    printf("please enter number of segments n :");
    scanf("%d",&n);
    printf("please enter xl :");
    scanf("%f",&xl);
    printf("please enter xu :");
    scanf("%f",&xu);
    printf("please enter a :");
    scanf("%f",&a);
    printf("please enter b :");
    scanf("%f",&b);
    printf("please enter c :");
    scanf("%f",&c);

    h=((xu-xl)/n);

    for(i=0; i<=n ; i++)
    {
        if(i==0)
        {
            x[i]=xl;
            y[i]=valuey(a,b,c,x[i]);
            printf("x=%f     ",x[i]);
            printf("y=%f\n",y[i]);
        }
        else
        {
            x[i]=x[i-1]+h;
            y[i]=valuey(a,b,c,x[i]);
            printf("x=%f     ",x[i]);
            printf("y=%f\n",y[i]);
            sum=sum+2*y[i];


        }
    }
    sum=sum+y[0]-y[n];
    inti=(((xu-xl)*sum)/(2*n));
    printf("INTIGRATION :%f",inti);
    ea=-((pow((xu-xl),3)/(12*n*n))*(2*a*xu-2*a*xl));
    printf("ERROR Ea :%f percent",ea);
}

float valuey(float a,float b,float c,float x)
{
    return a*x*x+b*x+c;
}
