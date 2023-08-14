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



    int large,temp;

   large=a[0][2];
      for(i=0 ; i<4 ; i++ )
    {
         for(j=0 ; j<4 ; j++ )
         {
            if(j==2)
            {
                if(a[i][j]>large)
                {
                    temp=large;
                    large=a[i][j];
                    a[i][j]=temp;
                }
            }
         }

    }

   printf("...........................");
    int k;
    for(k=0;k<4;k++)
    {

        printf("%d",a[k][2]);
    }
}
