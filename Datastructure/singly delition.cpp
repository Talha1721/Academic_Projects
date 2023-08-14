#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int i,n;
    struct node *list,*nptr,*tptr,*pptr;
    printf("how many number u want to insert :");
    scanf("%d",&n);
    list=NULL;
    printf("enter data :\n");
    for(i=1 ;i<n ; i++)
    {
        nptr=(struct node*)malloc(sizeof(struct node));
        nptr->next=NULL;
        scanf("%d",&nptr->data);

        if(list==NULL)
        {
            list=nptr;
            tptr=nptr;
        }
        else
        {
            tptr->next=nptr;
            tptr=nptr;
        }
    }

    tptr=list;

    struct node *pp;
    int dt;
    printf("enter data to delete:\n");
    scanf("%d",&dt);

    if(list->data==dt)
    {
        list=list->next;
    }
    else
    {
        while(tptr->data != dt)
    {
        pptr=tptr;
        tptr=tptr->next;
    }
    pptr->next=tptr->next;
    free(tptr);

    }

printf("updated list is :");
while(list!=NULL)
{
    printf("%d  ",list->data);
    list=list->next;
}


}
