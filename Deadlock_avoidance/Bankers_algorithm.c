#include <stdio.h>

int main()
{
    int n,m,i,j,k,p;
    int max[10][10],alloc[10][10],need[10][10];
    int avail[10],work[10],finish[10]={0},safe[10];
    int req[10];

    printf("Enter no. of processes and resources: ");
    scanf("%d%d",&n,&m);

    printf("Enter available resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);

    printf("Enter Maximum Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=max[i][j]-alloc[i][j];

    for(i=0;i<m;i++)
        work[i]=avail[i];

    int count=0;

    while(count<n)
    {
        int found=0;

        for(i=0;i<n;i++)
        {
            if(!finish[i])
            {
                for(j=0;j<m;j++)
                    if(need[i][j]>work[j])
                        break;

                if(j==m)
                {
                    for(k=0;k<m;k++)
                        work[k]+=alloc[i][k];

                    safe[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(!found)
        {
            printf("System is NOT Safe\n");
            return 0;
        }
    }

    printf("System is Safe\nSafe Sequence: ");
    for(i=0;i<n;i++)
        printf("P%d ",safe[i]);

    printf("\n\nEnter Process ID: ");
    scanf("%d",&p);

    printf("Enter Request Vector:\n");
    for(i=0;i<m;i++)
        scanf("%d",&req[i]);

    for(i=0;i<m;i++)
    {
        if(req[i]>need[p][i] || req[i]>avail[i])
        {
            printf("Request Denied\n");
            return 0;
        }
    }

    for(i=0;i<m;i++)
    {
        avail[i]-=req[i];
        alloc[p][i]+=req[i];
        need[p][i]-=req[i];
    }

    printf("Request Granted\n");

    return 0;
}