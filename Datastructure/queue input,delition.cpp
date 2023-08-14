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

printf("  queue addition   ");
printf("how many number u want to add :");
int n;
scanf("%d",&n);
    for(int i=0; i<n ; i++)
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
            rear->next=nptr;
            rear=nptr;
        }
    }


    struct node *tptr,*cptr;



    printf(" delition :");


    tptr=fron;
    fron=tptr->next;
    delete(tptr);


    while(fron!=NULL)
    {
        printf("%d  ",fron->data);
        fron=fron->next;

    }
}
