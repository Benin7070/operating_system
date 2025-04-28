#include <stdio.h>
#define MAX 10
char files[MAX][50];
int num_files;

void display(){
    if(num_files==0){
        printf("There is no files in the Directry.");
    }
    for(int i=0;i<num_files;i++){
        printf("%d. %s\n",i+1,files[i]);
    }
}
int main(){
    printf("\tSingle level Directry\n");
    printf("Enter the number of files: ");
    scanf("%d",&num_files);
    if(num_files>MAX){
        printf("The maximum number of files that can able to store id %d.",MAX);
        return 1;
    }
    for(int i=0;i<num_files;i++){
        printf("Enter the %d file name:",i+1);
        scanf("%s",files[i]);
    }
    display();
    return 0;
}