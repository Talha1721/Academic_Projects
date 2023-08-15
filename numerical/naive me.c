#include<stdio.h>
int main()
{
    int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
    printf("\nEnter the order of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<(n+1); j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&A[i][j]);
        }
    }
     for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(i<j)
            {
                c=A[j][i]/A[i][i];
                for(k=0; k<n+1; k++)
                {
                    A[j][k]=A[j][k]-c*A[i][k];
                }
            }
        }
    }
    int m,l;
    for(m=0 ; m<n ; m++)
    {
        for(l=0 ; l<n+1 ; l++)
        {
            printf("%f   ",A[m][l]);
        }
        printf("\n");

    }
}
