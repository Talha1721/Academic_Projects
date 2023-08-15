#include<stdio.h>
int main()
{
    int n,i,j,a,b,sum;
    while(scanf("%d",&n)==1)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            sum=0;
            if(a%2==0)
            {
                a=a+1;
            }
            for(j=a ; j<=b ; j=j+2)
            {
                sum+=j;
            }
            printf("Case %d: %d\n",i,sum);
        }
    }

    return (0);
}
