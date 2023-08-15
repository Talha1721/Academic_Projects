
#include<stdio.h>
int add(int i);
int main()
{
    int n,x;
    scanf("%d",&n);

    x=add((n+1)/2);
    printf("%d",x);
}

int add(int i)
{


    if (i==0)
    {
        return 0;
    }
    else
    {
        return ((2*i)-1) + add(i-1);
    }

}
