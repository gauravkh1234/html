#include<stdio.h>
#include<stdlib.h>
#include<string.h>
   
struct city {
    char name[20];
    int std;
};

struct city rec[20];


int binary_search(int n, char key[20],int low,int up) {
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(strcmp(rec[mid].name,key)==0) {
            return mid;
        } else if(strcmp(key, rec[mid].name)<0) {
            high=mid-1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    FILE *fp;
    fp = fopen("city.txt", "r");
    if(fp == NULL) {
        printf("Error opening file..\n");
        exit(0);
    }

    int i=0;
    while(!feof(fp)){
        fscanf(fp,"%s%d",rec[i].name, &rec[i].std);
        printf("%s %d\n",rec[i].name, rec[i].std);
        i++;
    }
    fclose(fp);

    printf("Enter key to search : ");
    char key[20];
    scanf("%s", key);

    i = binary_search(i, key);

    if(i == -1) {
        printf("Not found..");
    } else {
        printf("STD = %d", rec[i].std);
    }

    return 0;
}