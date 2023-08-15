#include<stdio.h>

int main()
{
    int k,x;
	scanf("%d",&x);
    for(k=1 ; k<=x ; k++)
    {
        int n, i, min=1000, max=0, num;
        scanf("%d", &n);

        for(i = 0; i < n; i++)
        {
            scanf("%d",&num);
            if (num > max)
                max = num;
            if (num < min)
                min = num;
        }

        printf("%d\n",(max-min)*2);
    }
    return 0;
}
