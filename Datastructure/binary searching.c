#include<stdio.h>
int main()
{
    int a[10],x;
    for(int i=0 ; i<10 ; i++)
    {
        printf("please enter data :\n");
        scanf("%d",&a[i]);
    }
    int f=0,l=10-1,m,c=0;
    printf( "your data : ");
    scanf("%d",&x);
    for(int k=0 ; k<10 ; k++)
    {
        c++;
        m=(f+l)/2;
        if(x==a[m])
            {
                printf("found");
                break;
            }
        else if(x<a[m])
        {
            l=m-1;
        }
        else
        {
            f=m+1;
        }
    }
    printf("\n");
    printf("etaration is : %d",c);
    if(f>l)
    {
        printf("\nnot found");
    }
}
