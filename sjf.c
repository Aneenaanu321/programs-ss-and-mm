#include<stdio.h>
int p[5]={1,2,3,4,5},bt[5]={2,4,3,1,2},ct[5],tat[5],wt[5],tt=0;
void sjf(){
    for(int i=0;i<5;i++){
        if (i==0)
            ct[i]=bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i];
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
            if(bt[j]>bt[j+1]){
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }
}
void main(){
    printf("P\tBT\n");
    for(int i=0;i<5;i++)
        printf("%d\t%d\n",p[i],bt[i]);
    sort();
    sjf();
    printf("P\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<5;i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],ct[i],tat[i],wt[i]);
}
