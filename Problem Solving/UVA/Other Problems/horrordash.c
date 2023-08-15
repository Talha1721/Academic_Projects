#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{   
	    int j;
	    for(j=1;j<=n;j++)
	    {
	    	int i,k,max=0,s[10000];
		    scanf("%d",&k);
	    	for(i=0 ; i<k ; i++)
		    {
			   scanf("%d",&s[i]);
			   if(s[i]>max)
			   max=s[i];
		    }
		  printf("Case %d: %d\n",j,max);
		}
	}
	return 0;
}
