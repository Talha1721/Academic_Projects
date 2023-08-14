#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct student
{

    int total;
    int  Smark[6];
    char name[10];
    int roll;


};



main()
{
    int i,j,k,l,m,x,n,sum=0,t=0;
    struct student Csebatch[40],a;
    char c[10];
    printf("\n Enter  number of student and subject ");
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
    {
        printf(" Information for student No:%d\n",i+1);
        printf("  \tStudent Name:\t");
        scanf("%s",&Csebatch[i].name);

        printf("\tEnter marks of his/her:>\t");
        for(j=0; j<m; j++)
        {
            scanf("%d",&Csebatch[i]. Smark[j]);
            sum=sum+ Csebatch[i].Smark[j];
        }
        printf("\ttotal:%d\n\n",sum);

        Csebatch[i].total=sum;
        sum=0;

    }



    for (i = 0; i < n; ++i)
    {


        for (j = i + 1; j < n; ++j)
        {
            if (Csebatch[i].total <Csebatch[j].total)
            {
                a = Csebatch[i];
                Csebatch[i] = Csebatch[j];
                Csebatch[j] = a;

            }
            else if(Csebatch[i].total ==Csebatch[j].total)

            {


                for(t=0;t<n;t++)
               {
                   if(Csebatch[i].Smark[t]<Csebatch[j].Smark[t])

                   {

                a = Csebatch[i];
                Csebatch[i] = Csebatch[j];
                Csebatch[j] = a;

                break;
                   }
                   else if(Csebatch[i].Smark[t]>Csebatch[j].Smark[t])
                   {
                       break;
                   }
                   else
                   {
                       continue;
                   }
               }



            }
        }
    }

    for(i=0; i<n; i++)
    {
        printf("\n%s",Csebatch[i].name);
    }




}

