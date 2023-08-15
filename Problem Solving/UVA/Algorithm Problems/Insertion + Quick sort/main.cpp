#include <bits/stdc++.h>

using namespace std;

int Partition(int A[],int p,int r)
{
    int x,i,j,temp;
    x=A[p];
    i=p-1;
    j=r+1;
    while(1)
    {
        do
        {
            j--;
        }while(!(A[j]<=x));

        do
        {
            i++;
        }while(!(A[i>=x]));

        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        else{
            return j;
        }
    }
}


void Quicksort(int A[],int p,int r)
{
    int q;
    if (p<r)
    {
        q=Partition(A,p,r);
        Quicksort(A,p,q);
        Quicksort(A,q+1,r);
    }
}

void Insertionsort(int A[],int n)
{
    int j,key_value,i;
    for(j=2;j<=n;j++)
    {
       key_value=A[j];
       i=j-1;
       while(i>0 && A[i]>key_value)
       {
           A[i+1]=A[i];
           i=i-1;
       }
       A[i+1]=key_value;
    }
}

int main()
{
    int A[40000],i,n=40000,j;
    for(i=40000;i>=0;i--)
    {
        A[i]=i;
    }
    Quicksort(A,20000,n);
    Insertionsort(A,20000);
   // insertion_sort();
    for(j=1;j<=n;j++)
    {
        printf("%d ",A[j]);
    }
    return 0;
}
