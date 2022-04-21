#include<stdio.h>
int at[5]={2,4,3,6,7},p[5]={1,2,3,4,5},bt[5]={2,1,1,2,1},ct[5],tat[5],wt[5],tt=0,idt;
void fcfs(){
    for(int i=0;i<5;i++){
        idt=0;
        while(tt<at[i]){
            tt++;
            idt++;
        }
        if (i==0)
            ct[i]=bt[i]+idt;
        else
            ct[i]=ct[i-1]+bt[i]+idt;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        tt+=bt[i];
    }
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(){
    for(int i=0;i<5-1;i++){
        for(int j=0;j<5-1;j++){
            if(at[j]>at[j+1]){
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }
}
void main(){
    printf("P\tAT\tBT\n");
    for(int i=0;i<5;i++)
        printf("%d\t%d\t%d\n",p[i],at[i],bt[i]);
    sort();
    fcfs();
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<5;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
}
