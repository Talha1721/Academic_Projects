#include <stdio.h>
#include <stdlib.h>

void lcs( char *x, char *y, int m, int n );

void lcs( char *x, char *y, int m, int n )
{
    int L[m+1][n+1];

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (x[i-1] == y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else

            {
                if(L[i-1][j] > L[i][j-1])
                    L[i][j]=L[i-1][j];
                else
                    L[i][j]=L[i][j-1];
            }
        }
    }
    printf(" the length of the lcs is : %d",L[m][n]);

    int index = L[m][n];
    char lcs[index+1];

    lcs[index] = '\0';
    index--;

    int i = m, j = n;
    while (i >= 0 && j >= 0)
    {

        if (x[i-1] == y[j-1])
        {
            lcs[index] = x[i-1];
            i--;
            j--;
            index--;
        }

        else if (L[i-1][j] > L[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }

    }
    puts(lcs);

}

int main()
{
    char x[100],y[100];
    printf("enter the string x :");
    gets(x);
    printf("enter the string y :");
    gets(y);
    int m,n;
    m=strlen(x);
    n=strlen(y);
    lcs(x,y,m,n);
    return 0;
}
