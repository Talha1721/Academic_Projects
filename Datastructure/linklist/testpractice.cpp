
#include <stdio.h>

#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *start,*t,*cur;
    start=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("how many number u want to scan : ");
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        printf("enter data for student %d : ",i);
        scanf("%d",&t->data);
        t->next=NULL;

        if(i==1)
        {
            start=t;

        }
        else
        {
             cur->next=t;

        }
        cur=t;
    }
    cur=start;


   struct node *u,*p;
   u=start;
   for(int k=1 ; k<=n ; k++)
   {

       if(u->data < start->data)
       {
           u->next=start;
           u=start;
       }
       for(int j=2 ; j<n ; j ++)
       {
           if(u->data > start->data)
           {
               start->next=u;
               u=u->next;
               start=start->next;
           }
       }
       u=start;
   }
   while(u!=NULL)
   {
       printf("%d",u->data);
       u=u->next;
   }

}
