#include<stdio.h>
#include<stdlib.h>

void calculateSeek(int l,int u,int *q,int *seektime,int *curr_head)
{
    int distance=0;
    for(int i=l;i<=u;i++){
        distance=abs((*curr_head-q[i]));
        *seektime+=distance;
        *curr_head=q[i];
        printf("%d ",*curr_head);
        //printf("%d\n",distance);
    }
    //printf("@@");
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int *q,int l,int n,int a)
{
     for(int i=l,k=0;i<n-1;i++,k++){
        for(int j=l;j<n-1-k;j++){
            if(a==1){
                if(q[j]>q[j+1])
                    swap(&q[j],&q[j+1]);
            }
            else{
                if(q[j]<q[j+1])
                    swap(&q[j],&q[j+1]);
            }
        }
    }
}

void main(){
   int *q,len,head,seektime=0,index,max=199,direction;
    printf("enter the length of the request sequence : ");
    scanf("%d",&len);
    q=(int*)malloc(len*sizeof(int));
    printf("enter the request sequence : ");
    for(int i=0;i<len;i++)
            scanf("%d",&q[i]);
    printf("enter the initial head position : ");
    scanf("%d",&head);
    printf("enter the direction\n0 : right to left\n1 : left to right\n");
    scanf("%d",&direction);
    sort(q,0,len,1);
        for(int i=0;i<8;i++){
            if(head<q[i]){
                index=i;
                break;
            }
        }
        printf("Seek sequence is : ");
        if(direction==0){
            sort(q,0,index,0);
            calculateSeek(0,index-1,q,&seektime,&head);
            seektime+=head+max;
            head=max;
            printf("0 %d ",head);
            sort(q,index,len,0);
            calculateSeek(index,len-1,q,&seektime,&head);
        }
        else{
            calculateSeek(index,len-1,q,&seektime,&head);
            seektime+=abs(head-max)+max;
            head=0;
            printf("%d %d ",max,head);
            calculateSeek(0,index-1,q,&seektime,&head);
        }
    printf("\nTotal number of seek operations = %d",seektime);
}
