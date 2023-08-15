#include<stdio.h>
//void arrpass(int*);
//int evod(int k);
int main()
{
  int a[10]={2,3,4,5,6};
  int *x;
  x=&a;
 arrpass(x);
}
void arrpass(int *c)
{

int z,i;

for( i=0 ; i<5 ; i++)
{
    z=evod(*(c+i));
    if(z==1){  printf("%d is a even number\n",*(c+i));   }
    else    {  printf("%d is a odd number\n",*(c+i));   }
}
}

int evod(int k)
{
    if(k%2==0)  {return 1;}
        else  {return 0; }
}
