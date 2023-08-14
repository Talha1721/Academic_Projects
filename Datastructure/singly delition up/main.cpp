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
    struct node *list,*nptr,*tptr,*pptr,*l;
    printf("how many number u want to insert :");
    scanf("%d",&n);
    list=NULL;
    printf("enter data :\n");
    for(i=1 ; i<=n ; i++)
    {
        nptr=(struct node*)malloc(sizeof(struct node));
        nptr->next=NULL;
        scanf("%d",&nptr->data);

        if(list==NULL)
        {
            list=nptr;
            tptr=list;
        }
        else
        {
            list->next=nptr;
            list=nptr;
        }
    }

    int dt;
    printf("enter the data to delete :");
    scanf("%d",&dt);
    while(list->data!=dt)
    {
        pptr=list;
        list=list->next;
        l=list;
    }

    pptr->next=list->next;
    free(l);
    list=tptr;
    while(list!=NULL)
    {
        printf("data is : %d\n",list->data);
        list=list->next;
    }

}
