#include<stdio.h>
#include<malloc.h>
struct node
{
    int roll;

    struct node *link;
};

int main()
{
    struct node *start,*last,*temp,*current;
   // start=(struct node *)malloc(sizeof(struct node));
    int n,i,r;
    scanf("%d",&n);

    for( i=1 ;i<=n ; i++)
    {

       temp =(struct node *)malloc(sizeof(struct node ));
       printf("enter roll for student %d :",i);
       scanf("%d",&r);

       temp->roll=r;
       temp->link=NULL;

       if(i==1)
        {      start=temp ;
                current=temp;
       }
       else
       {
            current->link=temp;
                current=temp;
                 }

    }
    current=start;
//    temp=start;



//temp =(struct node *)malloc(sizeof(struct node ));

while(current!=NULL)
{
     printf("%d",current->roll);
     current=current->link;
}


}
