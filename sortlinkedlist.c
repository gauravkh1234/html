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
    printf("how many nodes:");
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
void bsort(nodeptr slist)
{
    nodeptr p,q,end;
    for(end=NULL;end!=slist->next;end=p)
    {
        for(p=slist;p->next!=end;p=p->next)
        {
            q=p->next;
            if(p->data >q->data)
            {
                int t=p->data;
                p->data=q->data;
                q->data=t;
            }

        }
    }
}
int main()
{
    nodeptr slist=NULL;
    slist=create(slist);
    printf("\n data before sorting\n");
    display(slist);
    bsort(slist);
    printf("\n data after sorting\n");
    display(slist);
    return(0);
}