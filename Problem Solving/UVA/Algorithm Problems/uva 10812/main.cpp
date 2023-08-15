#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i,a,b,abso=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int s,d;
        cin>>s>>d;
        a=(s+d)/2;
        b=s-a;
        abso=a-b;
        if(a+b==s && abso==d)
        {
            if(a>b)
            {
                printf("%d %d\n",a,b);
            }
            else{
                printf("%d %d",b,a);
            }
        }
        else{
            printf("impossible\n");
        }
    }
    return 0;
}
