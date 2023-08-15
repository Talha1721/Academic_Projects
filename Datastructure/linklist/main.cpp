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
    printf("how many number u want to sscan");
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        printf("enter data for student %d",i);
        scanf("%d",t->data);
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
}
