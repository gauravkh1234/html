#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *create(NODE *slist)
{
    int i,n;
    NODE *temp,*newnode;
    printf("how many numbers");
    scanf("%d",&n);
    printf("enter %d numbers",n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        scanf("%d",&newnode->data);
        if(slist==NULL)
        {
            slist=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return slist;

}
void display(NODE *slist)
{
    NODE *temp=slist;
    while(temp!=NULL)
    {
        printf("%4d",temp->data);
        temp=temp->next;
    }
}
void b_sort(NODE *slist)
{
    NODE *p1,*p2;
    for(p1=slist; p1->next!=NULL; p1=p1->next)
    {
        for(p2=slist; p2!=NULL; p2=p2->next)
        {
           if((p1->data)<(p2->data))
           {
            int temp= p1->data;
            p1->data= p2->data;
            p2->data=temp;
           }
        }
    }
}
int main()
{
    NODE *slist=NULL;
    slist=create(slist);
    printf("data before sorting\n");
    display(slist);
    b_sort(slist);
    printf("\n data after sorting\n");
    display(slist);
    return(0);
}