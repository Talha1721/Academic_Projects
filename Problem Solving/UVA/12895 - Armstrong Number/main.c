#include<stdio.h>
#include<math.h>
int power(int a,int p)
{
    int res=1,i;
    for(i=1 ; i<=p ; i++)
    {
        res=res*a;
    }
    return res;
}
int main()
{
    int num;
    scanf("%d",&num);
    int d;
    for(d=1; d<=num; d++)
    {
        int sum=0,n,k,x,z,c=0;
        scanf("%d",&n);
        k=n;
        z=n;
        while(k!=0)
        {
            k=k/10;
            c++;
        }

        while(n!=0)
        {
            x=n%10;
            n=n/10;
            sum=sum+power(x,c);
        }

        if(sum==z)
        {
            printf("Armstrong\n");
        }
        else
        {
            printf("Not Armstrong\n");
        }
    }
return 0;
}
