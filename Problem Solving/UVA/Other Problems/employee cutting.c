#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{   
	  int i;
	  for(i=1 ; i<=n ; i++)
	  {
	  	int a,b,c,mid;
	  	scanf("%d%d%d",&a,&b,&c);
	  	if(a>b && b>c)
	  	mid=b;
	  	else if(a>c && c>b)
	  	mid=c;
	  	else if(b>c && c>a)
	  	mid=c;
	  	else if(b>a && a>c)
	  	mid=a;
	  	else if(c>a && a>b)
	  	mid=a;
	  	else 
	  	mid=b;
	  	printf("Case %d: %d\n",i,mid);
	  }
	}
	return 0;
}
