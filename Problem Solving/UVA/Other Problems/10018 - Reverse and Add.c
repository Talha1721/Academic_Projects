#include<stdio.h>
int main()
{
    int kase;
    long long int n,c,sum,r,d;
    scanf("%d",&kase);
    while (kase--)
    {
        scanf("%lld",&n);
        d=n;
        c=0;
        while (1)
        {
            sum=0;
            while (d>0)
            {
                r=d%10;
                sum=sum*10+r;
                d=d/10;
            }
            if (n==sum)
                break;
            else
            {
                d=sum+n;
                n=sum+n;
                c++;
            }
        }
        printf("%lld %lld\n",c,n);
    }
    return 0;
}
