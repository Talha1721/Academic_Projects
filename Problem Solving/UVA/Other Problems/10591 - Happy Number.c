/*
#include<stdio.h>
int squaresum(int n);
int squaresum(int n)
{
	int i,y,x,sum=0;
	y=n*n;
while(sum>9)
 {
	y=sum;
	while(y>9)
	{
	     	x=y%10;
	     	sum=sum+x*x;
	     	y=y/10;
	}
	sum=sum+y*y;
 }

	return sum;
}

 int main()
{
	int n,k;
	scanf("%d",&n);
	k=squaresum(n);
	printf("%d",k);

 return 0;
}

*/

#include<stdio.h>
void squaresum(int n);
void squaresum(int n)
{
	int i,y,x,sum=0;
	y=n*n;


	while(y>9)
	{
	     	x=y%10;
	     	sum=sum+x*x;
	     	y=y/10;
	}
	sum=sum+y*y;
if(sum>9)
   {
       squaresum(sum);
   }
else
    {
     printf("%d",sum);
	}
}

 int main()
{
	int n,k;
	scanf("%d",&n);
	squaresum(n);
	//printf("%d",k);

 return 0;
}
