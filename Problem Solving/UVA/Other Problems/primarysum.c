#include<stdio.h>
int main()
{
   long long int a,b,x,y;
  

    while(scanf("%lld%lld",&a,&b)!=EOF)
    { 
	    int sum=0,carry=0,count=0;
        if(a==0 && b ==0 )
        {
            break;
        }
        while(a!=0 && b!=0)
        {
            x=a%10;
            y=b%10;
            sum=x+y+carry;
            if(sum>9)
            {
                carry=sum/10;
                count+=carry;
            }
            a/=10;
            b/=10;
        }
        if(count==0)
        {
            printf("No carry operation\n");
        }
        else
        {
            printf("%d carry operation\n",count);
        }
    }
    return 0;
}

