#include<stdio.h>
int main()
{
    int n;

    scanf("%d",&n);
    int a[n+2];
    int i,j,k;
    printf("Lumberjacks:\n");
    for(i=1 ; i<=n ; i++ )
    {
        for(j=1 ; j<=10 ; j++)
        {
            scanf("%d",&a[j]);
        }

        for(j=1 ; j<10 ; j++)
        {
            if(a[j]>a[j+1])
                continue;
            else
            {
                break;
            }

        }
        for(k=1 ; k<10 ; k++)
        {
            if(a[k]<a[k+1])
            {
                continue;
            }

            else
            {
                break;
            }

        }
        if(j==10 || k==10)
            printf("Ordered\n");

        else
            printf("Unordered\n");



    }

}

