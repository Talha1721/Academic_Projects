#include<stdio.h>

void heapdown(int a[],int i,int n);


void heapdown(int a[],int i,int n)
{
    int l,r,largest,temp;
    l=2*i;
    r=2*i+1;
    if(l<n)
    {
        if(r<n)
        {
            if(a[l]<a[r])
            {
                largest=r;
            }
            else
            {
                largest=l;
            }
        }
        else
        {
            largest=l;
        }

        if(a[largest]>a[i])
        {

            temp=a[largest];
            a[largest]=a[i];
            a[i]=temp;
            heapdown(a,largest,n);
        }

    }
}

void exchange(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main()
{

    int n,i,j;
    scanf("%d",&n);
    int a[n];
    for(i=0; i<n; i++ )
    {
        scanf("%d",&a[i]);
    }

    for(j=n/2 ; j>=0 ; j--)
    {
        heapdown(a,j,n);
    }

    int k;
    for(k=0; k<n ; k++)
    {
        printf("%    d",a[k]);
    }
}
