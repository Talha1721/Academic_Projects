#include<stdio.h>
int deleteroot(int a[]);
int main()
{
    int i,j,k,n,root,lastindex,h;
    int a[n];
    for(i=1; i<=n ; i++)
    {
        scanf("%d",&a[i]);
    }
    int d[n];

     for(k=1; k<=n ; k++)
    {
        root=a[1];
        d[k]=root;
        deleteroot(a);

        lastindex=a[h];
        heapdownmain(a);
    }

}

int deleteroot(int a[])
{
    int temp;
    temp=a[1];
    int h=1;
    while(a[h]!=0)
    {
        a[h]=a[h+1];
        h++;
    }
    return h;
}
void heapdown()
{
     int temp;
     if(i>1)
     {
         int parentlocation=i/2;
         if(a[i]>a[parentlocation])
         {
             temp=a[i];
             a[i]=a[parentlocation];
             a[parentlocation]=temp;
             heapdown(a,parentlocation);
         }
     }
}

void heapdownmain(int a[])
{



    for(j=n ; j>1 ; j--)
    {
        heapdown(a,j);
    }

    int k;
    for(k=1; k<=n ; k++)
    {
        printf("%    d",a[k]);
    }
}
