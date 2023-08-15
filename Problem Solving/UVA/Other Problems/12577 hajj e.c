
#include<stdio.h>
#include<string.h>
int main()
{
    char a[10];
    char b[]="Hajj";
    char c[]="Umrah";
    char d[]="*";
    int i=1;

    while(scanf("%s",&a)!=EOF)
    {
        if(strcmp(a,b)==0)
        {
            printf("Case %d: Hajj-e-Akbar\n",i);
              i++;
        }
        else if(strcmp(a,c)==0)
        {
            printf("Case %d: Hajj-e-Asghar\n",i);
              i++;
        }
        else if(strcmp(a,d)==0)
        {
            break;
        }


    }





}
