#include<stdio.h>
int selection_search(int a[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
           return i;
    }
   return -1;
   
}
int main()
{
    int a[100],i,n,key,pos;
    printf("how many values");
    scanf("%d",&n);
    printf("enter %d numbers",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key to search");
    scanf("%d",&key);
   pos= selection_search(a,n,key);
    if(pos==-1)
    {
        printf("not found");
    }
    else{
        printf("found at %d index",pos);

    }
    return(0);
}
