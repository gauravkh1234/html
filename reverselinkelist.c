#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

typedef struct node *nodeptr;
nodeptr create(nodeptr slist)
{
    int i,n;
    nodeptr temp,newnode;
    printf("how many numbers:\n");
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
void display(nodeptr slist)
{
    nodeptr temp=slist;
    while(temp!=NULL)
    {
        printf("%4d",temp->data);
        temp=temp->next;
    }
}
nodeptr reverse(nodeptr slist)
{
    nodeptr current=slist;
    nodeptr prev=NULL;
    nodeptr nextptr;
    while(current!=NULL)
    {
        nextptr=current->next;
        current->next=prev;
        prev=current;
        current=nextptr;
    }
    return prev;
}
int main()
{
    nodeptr slist=NULL;
    slist=create(slist);
    printf("\ndata before sort\n");
    display(slist);
    slist=reverse(slist);
    printf("\n data after sort\n");
    display(slist);
    return(0);
}
