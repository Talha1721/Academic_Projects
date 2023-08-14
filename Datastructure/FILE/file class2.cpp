#include<stdio.h>
int main()
{
    FILE *f1,*f2;
    freopen("input.txt","r",stdin);
     //freopen("h:/output.txt","w",stdout);

     char str[1000];

     while(gets(str)!=NULL)
     {
         printf("%s",str);
     }


}

