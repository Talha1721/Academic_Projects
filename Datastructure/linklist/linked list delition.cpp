#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head,*start,*p,*q,*u;
    int i,n;
    printf("Enter the total  num u insert  : ");
    scanf("%d",&n);
    printf("\n insert numbers  :");
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





      printf ("\nenter the position to delete") ;
    int position;
    scanf ("%d", &position) ;


    struct node * t1, *t2, * t3;
    int cnt = 0;
    p = start;
    while (p!= NULL)
    {
        cnt++;

        if (cnt == position-1)
        {
            t1 = p;
            t2 =  p->next->next;
            t3 = p->next;

            t1->next = t2;

            free (t3);
            break;
        }

        p = p->next;

    }

    p = start;

    while(p!=NULL)
    {
        printf("->->%d\n",p->data);
        p=p->next;
    }



    return 0;

}
