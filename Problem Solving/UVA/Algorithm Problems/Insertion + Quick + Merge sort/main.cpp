#include <bits/stdc++.h>

using namespace std;

void Merge(int A[],int first,int mid,int last)
{
    int T[last];
    int i,j,k,b;
    i=first;
    j=mid+1;
    k=first;

    while(i<=mid && j<=last)
    {
        if(A[i]<=A[j])
        {
            T[k]=A[i];
            i++;
            k++;
        }
        else{
            T[k]=A[j];
            j++;
            k++;
        }
    }

    if(i>mid)
    {
        for(b=j;b<=last;b++)
        {
            T[k]=A[b];
            k++;
        }
    }
    else{
        for(b=i;b<=mid;b++)
        {
            T[k]=A[b];
            k++;
        }
    }
}


void merge_sort(int A[],int first,int last)
{
    int mid;
    if(first<last)
    {
      mid=(first+last)/2;
      merge_sort(A,first,mid);
      merge_sort(A,mid+1,last);
      Merge(A,first,mid,last);
    }
}

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
    int A[100000],n=100000,i,j;
    for(i=100000;i>=0;i--)
    {
        A[i]=i;
    }

    merge_sort(A,40000,n-1);
    Quicksort(A,20000,40000);
    Insertionsort(A,20000);

    for(j=1;j<=n;j++)
    {
        printf("%d ",A[j]);
    }
    return 0;
}
