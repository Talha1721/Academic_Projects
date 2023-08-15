#include<stdio.h>
int main()
{
    int t,i;
    double f,a,c,d;
    while(scanf("%d",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            scanf("%lf%lf",&c,&d);
             f = 9*c/5+32;
             f=f+d;
             a =((5*f-160)/9);
            printf("Case %d: %.2lf\n",i,a);
        }
    }
    return 0;
}
