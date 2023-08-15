#include<stdio.h>
int main()
{
    int cola,half;
    while(scanf("%d",&cola)==1)
    {
    if(cola==0)
    break;
    half=cola/2;
    printf("%d\n",half);
    }
    return 0;
}
