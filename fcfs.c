#include<stdio.h>
int main(){
    int process,burst[50],sum=0,turn[50],wait[50],total1=0,total2=0;
    printf("\tFCFS\n");
    printf("Enter the number of process:");
    scanf("%d",&process);
    
    for(int i=0;i<process;i++){
        printf("Enter the burst time of %d process:",i+1);
        scanf("%d",&burst[i]);
    }
    printf("\n");
    
    for(int i=0;i<process;i++){
        sum+=burst[i];
        turn[i]=sum;
        wait[i]=turn[i]-burst[i];
    }
    
    for(int i=0;i<process;i++){
        total1+=turn[i];
        total2+=wait[i];
    }
    float avg_turn=total1/process;
    float avg_wait=total2/process;
    
    printf("Process\tBurst time\tturn around time\twaiting time\n");
    for(int i=0;i<process;i++){
        printf("%d\t%d\t%d\t%d\n",i+1,burst[i],turn[i],wait[i]);
    }
    printf("\nAverage waiting time: %f",avg_wait);
    printf("\nAverage turn around time: %f",avg_turn);
}
    