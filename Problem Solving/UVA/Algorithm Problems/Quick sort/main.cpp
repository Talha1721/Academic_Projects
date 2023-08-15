#include <bits/stdc++.h>

using namespace std;

int Partition(int A[],int p,int r)
{
    int x,i,j,temp;
    x=A[p];
    i=p;
    j=r+1;

    do
    {
        do
        {
            i++;
        }while(A[i]<x && i<=r);

        do
        {
            j--;
        }while(x<A[j]);

        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<j);

    A[p]=A[j];
    A[j]=x;

    return j;
}


void Quick_sort(int A[],int p,int r)
{
    int j;
    if(p<r)
    {
        j=Partition(A,p,r);
        Quick_sort(A,p,j-1);
        Quick_sort(A,p+1,r);
    }
}

int main()
{
    int A[40000],n,i;
    n=40000;
    for(i=40000;i>=0;i--)
    {
        A[i]=i;
    }
    Quick_sort(A,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}



