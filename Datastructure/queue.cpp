#include<stdio.h>
#include<malloc.h>
int main()
{
    struct node
    {
        int data;
        node *next;
    };
    struct node *nptr,*rear,*fron;
    fron=NULL;
    rear=NULL;


    for(int i=0; i<5 ; i++)
    {
        nptr=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&nptr->data);
        nptr->next=NULL;

        if(rear==NULL)
        {
            rear=nptr;
            fron=nptr;
        }
        else
        {
            nptr->next=rear;
            rear=nptr;
        }
    }
    struct node *tptr,*cptr;


    int i,n;
    printf("u delete :");
   // scanf("%d",&n);

     tptr=fron;
        fron=tptr->next;
        delete(tptr);
       printf("u delete :");

   // cptr=NULL;
    //cptr=front;
    int j;
    for(int j=0 ; j<5 ; j++)
    {
        printf("%d",fron->data);
        fron=fron->next;

    }
}

