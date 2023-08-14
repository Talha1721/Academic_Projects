#include<stdio.h>
#include<malloc.h>
int main()
{
    struct node
    {
        int data;
        node *next;
    };
    struct node *nptr,*top,*start,*temp;
    top=NULL;

    for(int i=0; i<10 ; i++)
    {
        nptr=(struct node*)malloc(sizeof(struct node));
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
    }
    printf("\n  D  E  L  I  T  I  O  N  ");
    int j,k;
    struct node *tptr,*t;
    printf("how many number u want to delete :\n");
    scanf("%d",&k);

    for(j=0; j<k ; j++)
    {
       if(top->next!=NULL)
        {
            tptr=top;
            top=top->next;
            free(tptr);
        }
        else
        {
            top=NULL;
        }
    }
    while(top!=NULL)
    {
        printf("%d  ",top->data);
        top=top->next;
    }
}
