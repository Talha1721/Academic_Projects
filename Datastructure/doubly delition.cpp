#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
    int data;
    char name[100];
    node *back;
    struct node *link;

};
int main()
{
    struct node *tptr,*list,*nptr;
    int i;
    list=NULL;
    for( i=0; i<3 ;i++)
    {
        nptr=(struct node*)malloc(sizeof(struct node));
        nptr->link=NULL;
        nptr->back=NULL;
        printf( "enter data :");
        scanf("%d",&nptr->data);
        printf( "enter name :");
        gets(nptr->name);

        if(list==NULL)
        {
            list=nptr;
            tptr=nptr;
        }
        else
        {
            tptr->link=nptr;
            nptr->back=tptr;
            tptr=nptr;
        }
    }
    tptr=list;
    struct node *t;
    t=list;

    while(t!= NULL)
    {
        printf("%d",t->data);
        printf("%c",tptr->name);
        t=t->link ;
    }

}

