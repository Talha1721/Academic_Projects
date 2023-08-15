#include<stdio.h>
int main()
{
    int wn;
    printf("enter week number must be 1 to 7 : ");
    scanf("%d",&wn);
    if(wn==1)
    {
        printf("today is saturday");
    }
    else if(wn==2)
    {
        printf("today is sunday");
    }
    else if(wn==3)
    {
        printf("today is monday");
    }
    else if(wn==4)
    {
        printf("today is tuesday");
    }
    else if(wn==5)
    {
        printf("today is wedneday");
    }
    else if(wn==6)
    {
        printf("today is thursday");
    }

    else
    {
         printf("today is friday");
    }
    return 0;
}
