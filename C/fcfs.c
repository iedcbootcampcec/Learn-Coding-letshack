#include<stdio.h>
struct pcb{         //structure for a process
    int pid;
    int at;
    int bt;
    int complete;
    int wt;
    int tat;
};
void swap(struct pcb *p,struct pcb *q)
{
     struct pcb temp;
     temp=*p;
     *p=*q;
     *q=temp;
}



void main()
{
    int i,j,n,sum1=0,sum2=0;;
    float atat,awt;
    struct pcb p[20],temp;
    printf("enter the number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nenter the arrival time of %d:",i);
        scanf("%d",&p[i].at);
        p[i].pid=i;
    }
    for(i=0;i<n;i++)
    {
        printf("\nenter the burst time of %d:",i);
        scanf("%d",&p[i].bt);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)        //swapping based on arrival time
            {
                swap(&p[j],&p[j+1]);


            }
        }
    }
    p[0].complete=p[0].at+p[0].bt;    //completion time of first process is arrival time+burst time
    for(i=1;i<n;i++)
    {
        if(p[i].at<p[i-1].complete)
        {
            p[i].complete=p[i-1].complete+p[i].bt;   //if arrival time less than completion time of previous completion=previous completion+burst time
        }
        else{
            p[i].complete=p[i].at+p[i].bt;    //else completion time burst time +arrival time
        }

    }
    for(i=0;i<n;i++)
    {
        p[i].tat=p[i].complete-p[i].at;   //TAT=CT-AT
        sum1=sum1+p[i].tat;
    }
    for(i=0;i<n;i++)
    {
        p[i].wt=p[i].tat-p[i].bt;
        sum2=sum2+p[i].wt;              //WT=TAT-BT
    }
    printf("\nno\t\twait\t\ttat");

    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t%d\t\t%d",p[i].pid,p[i].wt,p[i].tat);

    }
    atat=sum1/(float)n;
    awt=sum2/(float)n;
    printf("\naverage turnaround time=%f,average waiting time=%f",atat,awt);
}

