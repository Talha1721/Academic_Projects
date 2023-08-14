#include<stdio.h>>
int main()
{
    char a[10][0],x=1;
    for(int j=0; j<10 ; j++)
    {
        gets(a[j][0]);
    }
    for(int i=1 ;i<=10; i=i*2)
    {

       x=x+i;
       if(i<=10)
       {
           printf("%d \t ",a[i]);
       }
         if(x<=10)
       {
           printf("%d  \n",a[x]);
       }

    }

}
