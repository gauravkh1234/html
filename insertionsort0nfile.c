#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100
 typedef struct employee
{
    int eno ;
    char ename[30];
    int age;
}emp;

emp rec[N];

void bubble_sort(int n)
{
    int i,c;
    char  t[30];
    for(c=1;c<n;c++)
    {
        for(i=0;i<n-c;i++)
        {
            if(strcmp(rec[i].ename,rec[i+1].ename)>0)
            {
                strcpy(t,rec[i].ename);
                strcpy(rec[i].ename,rec[i+1].ename);
                strcpy(rec[i+1].ename,t);
            }
        }
    }
}
void selection_sort(int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(rec[i].ename,rec[j].ename)>0)
            {
                emp t=rec[i];
                rec[i]=rec[j];
                rec[j]=t;
            }
        }
    }
}
int main()
{
    int i,n;
    FILE *fp;
    fp = fopen("employee.txt","w");
    if(fp==NULL)
    {
        printf("file opening error\n");
        exit(0);
    }

    printf("how many records of employee\n");
    scanf("%d",&n);

    printf("\nenter %d employee record eno ename and age\n",n);
    for(i=0;i<n;i++)
    {
        fscanf(stdin,"%d %s %d",&rec[i].eno,rec[i].ename,&rec[i].age);
        fprintf(fp,"%d %s %d\n",rec[i].eno,rec[i].ename,rec[i].age);
    }
    fclose(fp);

     fp = fopen("employee.txt","r");
    if(fp==NULL)
    {
        printf("file opening error\n");
        exit(0);
    }

    printf("data in employee.txt file");
    for(i=0;i<3;i++)
    {
        fscanf(fp,"%d %s %d",&rec[i].eno,rec[i].ename,&rec[i].age);
        printf("%d %s %d\n",rec[i].eno,rec[i].ename,rec[i].age);
    }

     selection_sort(3);
    printf("\ndata after sorting");
    for(i=0;i<3;i++)
    {
        printf("%d %s %d\n",rec[i].eno,rec[i].ename,rec[i].age);
    }
    return(0);
}
