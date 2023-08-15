#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,temp=0;
    scanf("%d %d",&n.&m);
    int A[m],i;
    for(i=0;i<m;i++)
    {
        scanf("%d",&A[i]);
    }
    sort(A,A+m);
    for(j=0;j<m;j++)
    {
        temp=A[j];
        for(k=j+1,p=j;j<m && p>=0;j++,p--)
        {
            if(A[j]==A[k])
            {
                continue;
            }
        }
    }
    return 0;
}
