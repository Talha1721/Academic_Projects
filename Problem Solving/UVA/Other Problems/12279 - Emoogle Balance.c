#include <stdio.h>
int main()
{
    int t=75,c=1,n,i,b,e,z;
    while (t--)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        z=0;
        for (i=0; i<n; i++)
        {
            scanf("%d",&e);
            if (e==0)
                z++;
        }
        b=n-(2*z);
        printf("Case %d: %d\n",c++,b);
    }
    return 0;
}
