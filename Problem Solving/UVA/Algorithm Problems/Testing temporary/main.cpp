#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int i,j,c=0;
     for(i=999999924;i<=1000000000;i++)
        {
            for(j=1;j<=i;j++)
            {
                if(i%j==0)
                {
                    c++;
                }
            }
        }
        printf("%d",c);


    return 0;
}
