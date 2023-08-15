#include<stdio.h>

int f91(int n)
{
	if(n<=100)
	{
		return f91(f91(n+11));
	}
	if(n>=101)
	{
		return n-10;
	}
}

int main()
{
	int n,x;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
		break;
		else
		x=f91(n);
		printf("f91(%d) = %d\n",n,x);
	}
	return 0;
}
