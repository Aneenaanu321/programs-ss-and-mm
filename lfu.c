Shortcuts simplify My Drive … 
In the coming weeks, items in more than one folder will be replaced by shortcuts. Access to files and folders won't change.Learn more
#include<stdio.h>
int main()
{
    int f,p;
    int pages[50],frame[10],hit=0,fault=0,count[50],time[50];
    int i,j,page,flag,least,minTime,temp;
    printf("Enter no of frames : ");
    scanf("%d",&f);
    printf("Enter no of pages : ");
    scanf("%d",&p);
    for(i=0;i<f;i++)
    {
            frame[i]=-1;
    }
    for(i=0;i<50;i++)
    {
        count[i]=0;
    }
    printf("Enter page no : \n");
    for(i=0;i<p;i++)
    {
        scanf("%d",&pages[i]);
    }
    for(i=0;i<f;i++)
    {
            printf("F%d\t",i+1);
    }
    printf("\n");
    for(i=0;i<p;i++)
    {
        count[pages[i]]++;
        time[pages[i]]=i;
        flag=1;
        least=frame[0];
        for(j=0;j<f;j++)
        {
            if(frame[j]==-1 || frame[j]==pages[i])
            {
                if(frame[j]!=-1)
                {
                    hit++;
                }
                else
                    fault++;
                flag=0;
                frame[j]=pages[i];
                break;
            }
            if(count[least]>count[frame[j]])
            {
                least=frame[j];
            }
        }
        if(flag)
        {
            fault++;
            minTime=50;
            for(j=0;j<f;j++)
            {
                if(count[frame[j]]==count[least] && time[frame[j]]<minTime)
                {
                    temp=j;
                    minTime=time[frame[j]];
                }
            }
            count[frame[temp]]=0;
            frame[temp]=pages[i];
        }
        for(j=0;j<f;j++)
        {
            printf("%d\t",frame[j]);
        }
        printf("\n");
    }
    printf("Page hit = %d Page fault = %d",hit,fault);
    return 0;
}
