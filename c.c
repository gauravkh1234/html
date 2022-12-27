#include<stdio.h>
#include<stdlib.h>
#include<string.h>
   
struct {
    char name[20];
    int std;
}rec[20];


int sentinel_search(int n, char key[20]) {
    int i = 0;
	char temp[20];
	strcpy(temp, rec[n-1].name);
	strcpy(rec[n-1].name, key);
	while (strcmp(rec[i].name, key)!=0) {
		i++;
	}
	strcpy(rec[n-1].name, temp);
	if (i<n-1 || (strcmp(rec[i].name,key)==0)) {
		return i;
	} else {
		return -1;
	}
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
        fscanf(fp,"%s%d",&rec[i].name, &rec[i].std);
        printf("%s %d\n",rec[i].name, rec[i].std);
        i++;
    }
    fclose(fp);

    printf("Enter key to search : ");
    char key[20];
    scanf("%s", key);

    i = sentinel_search(i, key);

    if(i == -1) {
        printf("Not found..");
    } else {
        printf("std = %d", rec[i].std);
    }

    return 0;
}