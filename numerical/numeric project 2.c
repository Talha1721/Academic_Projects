#include<stdio.h>
#include<math.h>

void naive_gauss();
void gauss_jordan();
void gauss_seidal();

int main()
{
    int ch;
    printf("1.NAIVE GAUSS \n2.GAUSS JORDAN  \n3.GAUSS SEIDAL \n");
    printf("enter your choise :");
    scanf("%d",&ch);
    if(ch==1)
    {
        naive_gauss();
    }
    if(ch==2)
    {
        gauss_jordan();
    }

    if(ch==3)
    {
        gauss_seidal();
    }
}


void naive_gauss()
{
    int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
    printf("\nEnter the order of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of matrix row-wise:\n\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(j<i)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];

    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]);
    }

}

void gauss_jordan()
{
    int i,j,k,n;
    float A[20][20],c,x[10];
    printf("\nEnter the size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
        }
    }

    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);
    }

}

void gauss_seidal()
{
    int i,j,n,l;
    float sum=0;
    printf("\nenter number of variable\t");
    scanf("%d",&n);
    float A[20][20],B[20],x[20]= {0,0,0,0};
    float big=100,old[20]= {0},Ea[20]= {0};


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%f",&A[i][j]);
        }
        printf("enter Value of b-%d\t",i);
        scanf("%f",&B[i]);

    }
    while(big>=.001)
    {
        for(l=1; l<=n; l++)
        {
            old[l]=x[l];

        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    sum=sum+A[i][j]*x[j];
                }
            }
            x[i]=(B[i]-sum)/A[i][i];////////develop
        }
        for(i=1; i<=n; i++)
        {
            Ea[i]=fabs(((x[i]-old[i])/x[i])*100);
            printf("\t%f",Ea[i]);

        }
        printf("\n");
        big=Ea[1];

        for(i=2; i<=n; i++)
        {
            if(big<Ea[i])
            {
                big=Ea[i];
            }
        }


        sum=0;



    }
    for(i=1; i<=n; i++)
    {

        printf("\nX%d %f",i,x[i]);
    }


}
