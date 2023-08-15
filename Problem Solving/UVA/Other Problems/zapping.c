#include<stdio.h>

int main()
{
    int a,b,i,s;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==-1 && b==-1)
            break;
        s = abs(a - b);
        if(s > 50)
            s = 100 - s;
        printf("%d\n", s);
    }
    return 0;
}
