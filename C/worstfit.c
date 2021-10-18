#include<stdio.h>
void main()
{
    int process_size[10],block_size[10],alloc[10]={0};
    int i,j,bno,pno,count=0,k,flag=0,l;
    printf("enter the number of blocks:\n");
    scanf("%d",&bno);
    printf("enter the number of processes:\n");
    scanf("%d",&pno);
    for(i=0;i<bno;i++)
    {
        printf("\nenter block%d size:",i);
        scanf("%d",&block_size[i]);
    }
     for(i=0;i<pno;i++)
    {
        printf("\nenter process%d size:",i);
        scanf("%d",&process_size[i]);
    }
     for(i=0;i<pno;i++)
    {

        flag=0;
        for(j=0;j<bno;j++)
        {
            if(process_size[i]<=block_size[j])
            {
                flag++;
                break;
            }
        }
            if(flag==0)
            {
                alloc[i]=-1;
            }
           else
           {
                alloc[i]=j;
                block_size[j]=block_size[j]-process_size[i];

           }

        }
}
