#include<stdio.h>
int main(){
    int p,pr[50],b[50],temp;
    printf("Enter the number of process:");
    scanf("%d",&p);
    for(int i=0;i<p;i++){
        printf("\nEnter the burst time of the %d process:",i+1);
        scanf("%d",&b[i]);
        pr[i]=i+1;
    }
    
    for(int i=0;i<p;i++){
        for(int j=i+1;j<p;j++){
            if(b[i]>b[j]){
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;
            }
        }
    }
    
    int tot[50],wait[50],avg_wait=0,avg_tot=0;
    wait[0]=0;
    tot[0]=pr[0];
    for(int i=1;i<p;i++){
        wait[i]=wait[i-1]+b[i-1];
        tot[i]=tot[i-1]+b[i];
        avg_wait+=wait[i];
        avg_tot+=tot[i];
    }
    avg_wait+=wait[0];
    avg_tot+=tot[0];
    
    printf("\nProcess\tburst time\twaiting time\nturn around time\n");
    for(int i=0;i<p;i++){
        printf("%d\t%d\t%d\t%d\n",pr[i],b[i],wait[i],tot[i]);
    }
}
