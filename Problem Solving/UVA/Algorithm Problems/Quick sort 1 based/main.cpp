#include<bits/stdc++.h>

using namespace std;

int Partition(int A[],int p,int r)
{
    int x,i,j,temp=0;
    x=A[p];
    i=p-1;
    j=r+1;
    while(1)
    {
        j--;
        while(A[j]>x)
        {
            j--;
        }
        i++;
        while(A[i]<x)
        {
            i++;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        else
        {
            return j;
        }
    }
}
void quick_sort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=Partition(A,p,r);
        quick_sort(A,p,q);
        quick_sort(A,q+1,r);
    }
}
int main()
{
    int i,n,p,r,c=40087;
    cin>>n;
    int A[n];
    for(i=1;i<=n;i++)
    {
        A[i]=c;
        c--;
    }
    quick_sort(A,1,n);
    for(i=1;i<=n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}

