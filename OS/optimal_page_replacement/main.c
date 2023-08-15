#include<stdio.h>
int main()
{
    int i,j=0,n,fno,t;
    int a[1000],frame[50];
    int exist,pfault=0;
    printf("ENTER THE NUMBER OF PAGES:");
    scanf("%d",&n);
     printf("\nENTER THE NUMBER OF FRAMES:");
    scanf("%d",&fno);

    printf("\n ENTER THE PAGE NUMBER :\n");
    for(i=1; i<=n; i++)
    {
         printf("\n Enter page[%d]:",i);
        scanf("%d",&a[i]);
    }
   printf("\n\n");

    for(i=0; i<fno; i++)
    {
         frame[i]= -99;
    }



//this is for printing heading
    printf("    pages            page frames\n\n");
    printf("     A[i]    ");
    for(int m=0; m<fno ; m++)
    {
       printf("fr[%d]     ",m);
    }
    printf("\n");

//...................................
//main calculation

    for(i=1; i<=n; i++)
    {
        printf("     %d\t\t",a[i]);
        exist=0;
        for(t=0; t<fno; t++)
        {
            if(frame[t]==a[i])
            exist=1;
        }

        if (exist==0)
        {
            frame[j]=a[i];
            j=(j+1)%fno;
            pfault++;
            for(t=0; t<fno; t++)
                printf("%d\t",frame[t]);
        }
        printf("\n");
    }
    printf("   Page Fault : %d",pfault);
    return 0;
}
