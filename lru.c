Shortcuts simplify My Drive … 
In the coming weeks, items in more than one folder will be replaced by shortcuts. Access to files and folders won't change.Learn more
#include<stdio.h>
#include<stdlib.h>
int linear(int *a,int n,int key){
    for(int i=0;i<n;i++)
        if(a[i]==key)
            return i;
    return -1;
}
int findmin(int *a,int n){
    int min =0;
    for(int i=1;i<n;i++)
        if(a[i]<a[min])
            min=i;
    return min;

}
void main(){
    int  j,i,size,*q,*qi,c,*r,pagefault=0,pagehit=0;
    printf("enter the size\n");
	scanf("%d",&size);
	q=(int*)malloc(size*sizeof(int));
    qi=(int*)malloc(size*sizeof(int));
	printf("enter the size of refernce string\n");
    scanf("%d",&c);
    r=(int*)malloc(c*sizeof(int));
	printf("enter the string: ");
	for(int i=0;i<c;i++)
	    scanf("%d",&r[i]);
    for(int i=0;i<size;i++){
        q[i]=-1;
        printf("F%d\t",i+1);
    }printf("\n");
    //inserting till frame is full
    for(i=0,j=0;j<size;i++){
        if(linear(q,j,r[i])==-1){
            q[j]=r[i];
            qi[j]=i;
            pagefault++;j++;
        }
        else{
            int index=linear(q,j,r[i]);
            qi[index]=i;
            pagehit++;
        }
        for(int i=0;i<size;i++)
            printf("%d\t",q[i]);
        printf("\n");
    }
    //rpalcing the pages
    while(i<c){
        int index=linear(q,size,r[i]);
        if(index==-1){
            pagefault++;
            int x=findmin(qi,size);
            q[x]=r[i];
            qi[x]=i;
        }
        else
        {
            qi[index]=i;
            pagehit++;
        }
        i++;
        for(int i=0;i<size;i++)
            printf("%d\t",q[i]);
        printf("\n");
    }
    printf("pagefault:%d pagehit:%d",pagefault,pagehit);
}
