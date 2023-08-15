#include<stdio.h>
#include<math.h>
main()
{

    int i,j,n,l;
    float sum=0;
    printf("\nenter number of variable and number of equation\t");
    scanf("%d",&n);
    float A[20][20],B[20],x[20]={0,0,0,0};
    float big=100,old[20]={0},Ea[20]={0};


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
        for(l=1;l<=n;l++)
        {
            old[l]=x[l];

        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    sum=sum+A[i][j]*x[j];
                }
            }
            x[i]=(B[i]-sum)/A[i][i];////////develop
        }
        for(i=1;i<=n;i++)
        {
           Ea[i]=fabs(((x[i]-old[i])/x[i])*100);
           printf("\t%f",Ea[i]);

        }
        printf("\n");
        big=Ea[1];

          for(i=2;i<=n;i++)
        {
           if(big<Ea[i])
           {
               big=Ea[i];
           }
        }


        sum=0;



    }
    for(i=1;i<=n;i++)
    {

        printf("\nX%d %f",i,x[i]);
    }


}
