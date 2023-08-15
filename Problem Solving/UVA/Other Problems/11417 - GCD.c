#include<stdio.h>

int gcd(int i, int j)
{
    int k,gc;
    for(k=1; k<=i && k<=j ; ++k)
    {

        if(i%k==0 && j%k==0)
            gc=k;
    }
    return gc;
}


int main()
{
    int i,j,sum=0,n=0;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;

        sum=0;
        for(i=1; i<n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                sum+=gcd(i,j);
            }
        }
        printf("%d\n",sum);
    }

    return 0;

}
