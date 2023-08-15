
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void quick_sort(int a[],int p,int r);
int Partition(int a[],int p,int r)
{
    int x,i,j,t=0;
    x=a[p];
    i=p-1;
    j=r+1;
    while(1)
    {
        j--;
        while(a[j]>x)
        {
            j--;
        }
        i++;
        while(a[i]<x)
        {
            i++;
        }
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        else
        {
            return j;
        }
    }
}
void quick_sort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=Partition(a,p,r);
        quick_sort(a,p,q);
        quick_sort(a,q+1,r);
    }
}
int main()
{
    int i,n,p,r,c=40088;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        //cin>>a[i];
        a[i]=c;
        c--;
    }
    quick_sort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
