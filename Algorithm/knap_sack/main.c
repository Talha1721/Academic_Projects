#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,w,WT,i,nn,wwtt;
    printf("knapsack weight :");
    scanf("%d",&WT);
    wwtt=WT;
    printf("total process : ");
    scanf("%d",&n);
    nn=n;

    int wt[n];
    int b[n],l=0;
    printf("each weight and value:\n");
    for(i=1 ; i<=n ; i++)
    {
        scanf("%d%d",&wt[i],&b[i]);
    }
    int B[n+1][WT+1];


    for(i=0; i<=n ; i++ )
    {
        for(w=0 ; w<=WT ; w++)
        {
            if(w==0 || i==0)
            {
                B[i][w]=0;
            }

            else if (wt[i]<=w)
            {
                if((b[i]+B[i-1][w-wt[i]])>B[i-1][w])
                {
                    B[i][w]=b[i]+B[i-1][w-wt[i]];
                    //l++;
                }
                else
                {
                    B[i][w]=B[i-1][w];
                }
            }
            else
            {
                B[i][w]=B[i-1][w];
            }

        }
    }
    printf("result1:%d\n",B[n][WT]);
    int res=B[n][WT];


    i=n;
    w=WT;
    while(i>0 )
    {
        if (res == B[i - 1][w])
        {
            i--;
            continue;
        }

        else
        {

            // This item is included.
            printf("item %d weight %d\n", i,wt[i]);

            // Since this weight is included its
            // value is deducted
            res = res - b[i];
            w = w - wt[i];
            i--;
        }

    }

}

