#include<stdio.h>
void insertion_sort(int n,int a[])
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;

        }
        a[j+1]=temp;
    }
}
int main()
{
    int a[100],n,i;
    printf("how mant numbers");
    scanf("%d",&n);
    printf("enter %d numbers",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertion_sort(n,a);
    printf("\n after sorting elements");
    for(i=0;i<n;i++)
    {
        printf("%4d",a[i]);
    }
    return(0);
}