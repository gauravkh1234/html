#include<stdio.h>
int linear_search(int n,int a[],int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
           return i;
        }
    }
    return -1;
}
int main()
{
    int a[100],i,n,key;
    printf("enter how many values");
    scanf("%d",&n);
    printf("enter %d values",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key to search\n");
    scanf("%d",&key);
    i=linear_search(n,a,key);
    if(i==-1)
    {
        printf("not found");
    }
    else{
        printf("found at %d position",i+1);
    }
    return(0);
}