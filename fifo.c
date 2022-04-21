#include<stdio.h>
#include<stdlib.h>
int *q,*f,n,fs,fp=0;
int search(int key){
    for(int i=0;i<fs;i++){
        if(f[i]==key)
            return -1;
    }
    return 1;
}
void fifo(){
    int pagehit=0,pagefault=0;
    for(int i=0;i<fs;i++)
        printf("F%d\t",i+1);
    printf("\n");
    for(int i=0;i<n;i++){
        if(search(q[i])==1){
            f[fp]=q[i];
            fp=(fp+1)%fs;
            pagefault++;
        }
        else 
            pagehit++;
        for(int i=0;i<fs;i++)
            printf("%d\t",f[i]);
        printf("\n");
    }
    printf("Pagefault : %d\tPagehit : %d\n",pagefault,pagehit);
}
void main(){
    printf("enter the size of reference string\n");
    scanf("%d",&n);
    q=(int*)malloc(n*sizeof(int));
    printf("enter the reference string\n");
    for(int i=0;i<n;i++)
        scanf("%d",&q[i]);
    printf("enter the number of frames\n");
    scanf("%d",&fs);
    f=(int*)malloc(fs*sizeof(int));
    for(int i=0;i<fs;i++)
        f[i]=-1;
    fifo();
}
