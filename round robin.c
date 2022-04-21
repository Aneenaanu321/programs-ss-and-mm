#include<stdio.h>
int p[5]={1,2,3,4,5},bt[5]={21,18,12,30,15},ct[5],tat[5],wt[5],tt=0,tqt=0,qt=6,todo=0,BT[5];
void sjf(){
    while(todo==0){
        todo=-1;
        for(int i=0;i<5;i++){
            tqt=0;
            while(tqt<qt && bt[i]!=0){
                todo=0;tt++;
                ct[i]=tt;
                tat[i]=ct[i];
                bt[i]--;
                tqt++;
            }
            
            wt[i]=tat[i]-BT[i]; 
        }
    }
}
void main(){
    printf("P\tBT\n");
    for(int i=0;i<5;i++){
        printf("%d\t%d\n",p[i],bt[i]);
        BT[i]=bt[i];
    }
    sjf();
    printf("P\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<5;i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],BT[i],ct[i],tat[i],wt[i]);
}
