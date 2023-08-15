#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head,*start,*p,*q,*u,*g,*h;
    int i,n;
    printf("Enter the total  num u insert  : ");
    scanf("%d",&n);
    printf("\ninsert numbers  :");
    for(i=0;i<n;i++)
    {
        head = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&head->data);
        head->next = NULL;
        if(i==0)
        {
            start = head;
        }
        else
        {
            p->next  = head;
        }
        p=head;
    }
    p=start;

    int c;
    q= (struct node *)malloc(sizeof(struct node));
    printf("\nInsert position  :");
    scanf("%d",&c);
    printf("\nInsert data :");
    scanf("%d",&q->data);
    q->next = NULL;
    if(c==1)
    {
        u=start;
        start = q;
        q->next = u;
        p= start;
    }
    else{
    for(i=0;i<c-2;i++)
    {
        p=p->next;
    }

//    q->next = p->next; by sir
  //  p->next = q;

    //p->next=q;
    //q=p->next->next;  by me
    g=p;
    h=p->next;
    g->next=q;
    q->next=h;



    p=start;
    }

    while(p!=NULL)
    {
        printf("->->%d\n",p->data);
        p=p->next;
    }

}
