#include<stdio.h>
int main()
{
    int i,j,a[4][4];
    for(i=0 ; i<4 ; i++ )
    {
        for(j=0 ; j<4 ; j++ )
        {
            scanf("%d",&a[i][j]);
        }

    }



    int large,temp,k,l;

    large=a[0][2];
    for(i=0 ; i<4 ; i++ )
    {
        for(j=0 ; j<4 ; j++ )
        {
            if(j==2)
            {
                for(k=0; k<3 ; k++)
                {
                    for(l=0;l<4-k;l++)
                    {

                        if(a[i+1][j]>a[i][j])
                        {
                            temp=a[i][j];
                            a[i][j]=a[i+1][j];
                            a[i+1][j]=temp;
                        }
                    }

                }


            }
        }

    }

    printf("...........................");
    printf("%d\n",large);

    int n;
    for(n=0; n<4; n++)
    {

        printf("%d          ",a[n][2]);
    }
}
/*
int main()
{
    int a[6],i,temp;
    for(i=0; i<6 ;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<6 ;i++)
    {
        if(a[i+1]>a[i])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
     for(i=0; i<6 ;i++)
    {
        printf("%d     ",a[i]);
    }
}
