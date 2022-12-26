#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct employee
{
    int eno;
    char ename[30];
    int age;
}emp;

emp rec[N];
void insertion_sort(int n)
{
    int i,c;
    emp t[30];
    for(c=0;c<n-1;c++)
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
int main()
{
    int i,n;
    FILE *fp;
    fp = fopen("employee.txt","w");
    if(fp==NULL)
    {
        printf("error opening file\n");
        exit(0);
    }

    printf("how many records");
    scanf("%d",&n);

   printf("enter %d record",n);
   for(i=0;i<n;i++)
   {
      fscanf(stdin,"%d %s %d",&rec[i].eno,rec[i].ename,&rec[i].age);
      fprintf(fp,"%d %s %d\n",rec[i].eno,rec[i].ename,rec[i].age);
   }
   fclose(fp);
    fp = fopen("employee.txt","r");
    if(fp==NULL)
    {
        printf("error opening file\n");
        exit(0);
    }

    printf("\n data in employe.txt file");
    for(i=0;i<3;i++)
    {
        fscanf(fp,"%d %s %d",&rec[i].eno,rec[i].ename,&rec[i].age);
        printf("%d %s %d\n",rec[i].eno,rec[i].ename,rec[i].age);
    }

    insertion_sort(3);

    printf("\n data after sortinf\n");
    for(i=0;i<3;i++)
    {
        printf("%d %s %d\n",rec[i].eno,rec[i].ename,rec[i].age);
    }
    return(0);

}