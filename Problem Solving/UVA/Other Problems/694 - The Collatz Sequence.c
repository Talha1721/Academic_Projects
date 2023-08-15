#include<stdio.h>
int main()
{
	int n,l,a,c=0;
	while(scanf("%d%d",&n,&l)==2)
	{   a=n;
		c++;
		if(n<0 && l<0 )
		break;
		int k=0;
		while(n<=l)
		{
			k++;
			if(n==1)
			break;
			else if(n%2==0)
			n/=2;
			else
			n=3*n+1;
		}
		
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",c,a,l,k);
	}
	return 0;
}

