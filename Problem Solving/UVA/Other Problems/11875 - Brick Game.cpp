#include<stdio.h>
int main()
{
	int n,i,k,c,l,t;

	while(scanf("%d",&n)==1)
	
	{
	
		for(l=1 ; l<=n ;l++)
		{
			scanf("%d",&i);
	     	int a[i];
			c=(i/2);
	    	for(k=0 ; k<i ; k++)
	    	{
		    	scanf("%d",&a[k]);
	    	}
	
		printf("Case %d: %d\n",l,a[c]);
	
		}
		
}
		
	
	return 0;
}


