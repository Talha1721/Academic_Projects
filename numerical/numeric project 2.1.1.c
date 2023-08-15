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
     int X;
    printf("enter your row num :");
    scanf("%d",&X);
    float x[X][X+1],a[X], ae, max,t,s,e;
    int i,j,r,mxit;
    for(i=0;i<X;i++) a[i]=0;
    puts(" Eneter the elemrnts of augmented matrix rowwise\n");
    for(i=0;i<X;i++)
    {
    for(j=0;j<X+1;j++)
    {
        printf("A[%d][%d] :",i,j);
    scanf("%f",&x[i][j]);
    }
    }
    printf(" Eneter the allowed error and maximum number of iteration: ");
    scanf("%f%d",&ae,&mxit);
   printf("Iteration\tx[1]\tx[2]\tx[3]\n");
    for(r=1;r<=mxit;r++)
    {
        max=0;
        for(i=0;i<X;i++)
        {
            s=0;
            for(j=0;j<X;j++)
            if(j!=i) s+=x[i][j]*a[j];
            t=(x[i][X]-s)/x[i][i];
            e=fabs(a[i]-t);
            a[i]=t;
        }
        printf(" %5d\t",r);
        for(i=0;i<X;i++)
        printf(" %9.4f    ",a[i]);
        printf("\n");


        }
}

