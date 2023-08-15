#include<stdio.h>
int main()
{
	int n,a,b,x,y,i;
	while(scanf("%d",&n)==1)
	{
		for(i=1 ;i<=n ; i++)
		{
			scanf("%d %d",&a,&b);
                  if (a>=b&&(a+b)%2==0)
                   {
                   x=(a+b)/2;
                   y=(a-b)/2;
                   printf("%d %d\n",x,y);
                   }
         else
         printf("impossible\n");
         
		}
	}
	
	return (0);
}
