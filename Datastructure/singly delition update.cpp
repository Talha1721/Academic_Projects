#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    printf("ggggggggggggggggggggggggggggggggggggggggggg");
    int i,n;
    struct node *list,*nptr,*tptr,*pptr;
    printf("how many number u want to insert :");
    scanf("%d",&n);
    list=NULL;
    printf("enter data :\n");
    for(i=1 ;i<=n ; i++)
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
    list=tptr;
    while(list!=NULL)
    {
        printf("data is : %d",list->data);
        list=list->next;
    }
}
