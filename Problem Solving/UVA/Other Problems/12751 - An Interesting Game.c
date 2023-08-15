#include<stdio.h>
long long count;
int main()
{
    int tst,i,k,x,cs=1,n;
    scanf("%d",&tst);
    while(tst--)
    {
        count=0;
        scanf("%d %d %d",&n,&k,&x);
        for(i=1; i<x; i++)
            count+=i;

        for(i=x+k; i<=n; i++)
            count+=i;

        printf("Case %d: %lld\n",cs++,count);

    }

    return 0;
}

