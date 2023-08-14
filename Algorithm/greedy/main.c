#include <stdio.h>
#include <stdlib.h>

struct ride
{
    int st;
    int ft;
    char name[100];
};
int main()
{
    int n;
    scanf("%d",&n);
    struct ride r[n];

    int i;
    int j;
    for(i=0 ; i<n ; i++)
    {

        scanf("%d",&r[i].st);
        scanf("%d",&r[i].ft);
        gets(r[i].name);

    }

    struct ride temp;
    for(i=0 ; i<n ; i++)
    {
        for(j=i+1 ; j<n ; j++)
        {
            if(r[i].ft>r[j].ft)
            {
                temp =r[i];
                r[i]=r[j];
                r[j]=temp;
            }
        }
    }
    for(i=0 ; i<n ; i++)
    {
        printf("%d",r[i].st);
        printf("%d",r[i].ft);
        puts(r[i].name);
    }

    int k=0;

    int ss=0;
    int ff=1;
    puts(r[ss].name);
    while(ff<n)
    {
        if(r[ss].ft<=r[ff].st)
        {
            puts(r[ff].name);
            ss=ff;
            ff++;
        }
        else
        {
            ff++;
        }

    }

}
