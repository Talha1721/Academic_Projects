#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,i,ans=0,c=0,temp=0;
    cin>>n>>k;
    cin.ignore(256,'\n');
    string s;
    getline(cin,s);
    int l=s.length();
    int a[5];
    for(i=0;i<5;i++)
    {
        if(a[i]==' ')
        {
            a[i]=200;
        }
        else{
            a[i]=s[i];
        }
    }
    sort(a,a+l);
    for(i=0;i<s.length();i++)
    {
        if(i==0)
        {
            ans=ans+a[0]-96;
            temp=a[0];
        }
        else if(a[i]!=temp && a[i]!=temp+1)
        {
            ans=ans+a[i]-96;
            temp=a[i];
        }
        c++;
        if(c==k)
        {
            break;
        }

    }
    if(c==k)
    {
        printf("%d",ans);
    }
    else{
        printf("-1");
    }
    return 0;
}
