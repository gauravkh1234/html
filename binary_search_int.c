#include<stdio.h>

int binary_search(int n,int a[],int key)
{
    int low=0,mid,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(key>a[mid])
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }


    }
    return -1;
}
int main()
{
    int a[100],i,n,key;
    printf("enter how many numbers");
    scanf("%d",&n);
    printf("enter %d numbers",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key to search:");
    scanf("%d",&key);
    i=binary_search(n,a,key);
    if(i==-1)
    {
        printf("not found");
    }
    else{
        printf("found at %d position",i+1);
    }
    return(0);
}