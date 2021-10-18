#include<stdio.h>
struct pcb{
   int at;
   int bt;
   int wt;
   int ct;
   int tat;
   int p;
};

void main()
{
    int n,i,j;
    struct pcb temp;
    int  sum=0,sum1=0;
    float awt,atat;
    struct pcb p[10];
    printf("\nenter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nenter the arrival time of process %d",i+1);
        scanf("%d",&p[i].at);
        p[i].p=i;
    }
    for(i=0;i<n;i++)
     {
        printf("\nenter the burst time of process %d",i+1);
        scanf("%d",&p[i].bt);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
               temp=p[j];
               p[j]=p[j+1];
               p[j+1]=temp;
            }
        }

    }
    p[0].ct=p[0].at+p[0].bt;
    for(i=1;i<n;i++)
    {
        if(p[i].at<p[i-1].ct)
        {
            p[i].ct=p[i-1].ct+p[i].bt;
        }
        else
        {
            p[i].ct=p[i].at+p[i].bt;
        }

    }
    for(i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        sum+=p[i].tat;
    }
    for(i=0;i<n;i++)
    {
        p[i].wt=p[i].tat-p[i].bt;
        sum1+=p[i].wt;

    }
    printf("\nProcess\t\tat\t\tbt\t\tct\t\twt\t\ttat");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].p,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
    }
    awt=sum1/(float)n;
    atat=sum/(float)n;
    printf("\naverage turnaround time=%f",atat);
    printf("\naverage waiting time=%f",awt);

}

