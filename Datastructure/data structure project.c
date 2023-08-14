
#include<stdio.h>
struct std
{
    char name[20];
    int roll;
    float marks[7];
} s[40] ;

main()
{
    int n;

    printf("\nEnter number of student");
    scanf("%d",&n);
    float total[n];
    for(int i=0 ; i<n ; i++)
    {
        printf("\nenter %d-student name ",i+1);
        scanf("%s",s[i].name);
         total[i]=0;
        for(int j=0 ; j<7 ; j++)
        {
            printf("\nenter %d-student%d-subject mark ",i+1,j+1);
            scanf("%f",&s[i].marks[j]);
            total[i]=total[i]+s[i].marks[j];
        }


    }


 for(int i=0 ; j<n ; j++)///print section
 {

 }


}
