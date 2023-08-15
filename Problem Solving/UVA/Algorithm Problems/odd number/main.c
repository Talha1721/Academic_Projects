#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int a,b,i,j,c,sum=0;
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&a,&b);
        if(a>b)
        {
            c=a;
            a=b;
            b=c;
        }
        for(j=a;j<=b;j++)
        {
           if(j%2!=0)
            sum=sum+j;
        }
        printf("Case %d: %d\n",i+1,sum);
        sum=0;
    }
    return 0;
}
