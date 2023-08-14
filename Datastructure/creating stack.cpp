#include<stdio.h>
#include<malloc.h>
int main()
{
    struct node
    {
        int data;
        node *next;
    };

    struct node *top,*nptr;
    top=NULL;
    for(int i=0; i<6; i++)
    {

        nptr=(struct node*)malloc(sizeof(node));
        scanf("%d",&nptr->data);
        nptr->next=NULL;
        if(top==NULL)
        {
            top=nptr;
        }
        else
        {
            nptr->next=top;
            top=nptr;
        }
  printf("%d",top);
    }

   /* for(int i=0; i<6; i++)
    {

    }*/


}
