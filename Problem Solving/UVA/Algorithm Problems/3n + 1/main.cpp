#include <iostream>
using namespace std;

int main()
{
    long long int a,b,p,big=0,i,j,n,q;
    while(cin>>a>>b)
    {
        big = 0;
        i=a;
        j=b;
        if(i>j)
        {
            int c;
            c=i;
            i=j;
            j=c;
        }
        n=i;
        while(n<=j)
        {
            p=1;
            q=n;
            while(q!=1)
            {
                if(q%2!=0)
                {
                    q=3*q+1;
                }
                else
                {
                    q=q/2;
                }
                p++;
            }
            if(big<p)
            {
                big = p;
            }
            n++;
        }
        cout<<a<<" "<<b<<" "<<big<<endl;
    }

    return 0;
}
