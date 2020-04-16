#include<stdio.h>
#include<conio.h>
int main()
{
    int x;
    printf("-----------------------------------");
    printf("\nEnter the number of process : ");
    scanf("%d",&x);
    printf("-----------------------------------\n\n");
    int arr[x], bur[x], priority[x], process[x], quantumtime;
    int i;

    for(i=0;i<x;i++)
    {
        printf("-----------------------------------\n");
		printf("For Process P%d :-\n",i+1);
        printf("Enter Priority : ");
        scanf("%d",&priority[i]);
        printf("Enter the Burst Time : ");
        scanf("%d",&bur[i]);
        printf("Enter the Arrival Time : ");
        scanf("%d",&arr[i]);
        printf("-----------------------------------\n");
        printf("\n");
    }
    printf("-----------------------------------");
    printf("\nEnter time quantum : ");
    scanf("%d",&quantumtime);
    printf("-----------------------------------\n\n");

    int pos, j, swap;
    for(i=0;i<x;i++)
	{
		pos=i;
		for(j=i+1;j<x;j++)
		{
			if(arr[j]<arr[pos])
   			pos=j;
		}
		swap=bur[i];
		bur[i]=bur[pos];
		bur[pos]=swap;
		swap=arr[i];
		arr[i]=arr[pos];
		arr[pos]=swap;
        swap=priority[i];
		priority[i]=priority[pos];
		priority[pos]=swap;
		swap=process[i];
		process[i]=process[pos];
		process[pos]=swap;
	}

    float waiting, turnaround;
    int newbur[x];
    for (i=0; i<x; i++)
    {
        newbur[i]=bur[i];
    }
    int time, remain = x, flag = 0, z = x, y = x, idle = 0;
    printf("---------------------------------------------------------");
    printf("\nProcess\t\tTurnaround Time\t\tWaiting Time\n");
    printf("---------------------------------------------------------");
    while(z)
    {
        for( time=0, i=0; remain!=0;)
        {
            if(newbur[i]<=quantumtime && newbur[i]>0)
            {
                time=time+newbur[i];
                newbur[i]=0;
                flag=1;
            }
            else if(newbur[i]>0)
            {
                newbur[i] = newbur[i] - quantumtime;
                time = time + quantumtime;
            }
            if(newbur[i]==0 && flag==1)
            {
                remain--;
                printf("\nP%d\t\t\t%d\t\t\t%d\n",i+1,time-arr[i],time-arr[i]-bur[i]);
                
                waiting = waiting + time - arr[i] - bur[i];
                turnaround = turnaround + time - arr[i];
                flag = 0;
                z--;
            }
            if(i==y-1)
                i=0;
            if((arr[i+1]>time && newbur[i]==0))
            {
                idle = idle + (arr[i+1] - time);
                time = (time + (arr[i+1] - time));
                i++;
            }
            else if(arr[i+1] <= time)
            {
                i++;
            }
       }
    }
    printf("---------------------------------------------------------\n\n");
    printf("---------------------------------------------------------");
    printf("\nIdle Time : %d  \n",idle);
    printf("---------------------------------------------------------");
    float utilpercentage = (time - idle) * 100;
    printf("\n\n---------------------------------------------------------");
    printf("\nCPU Utilization Percentage : %f\n",utilpercentage/time);
    printf("---------------------------------------------------------");
    printf("\n\n---------------------------------------------------------");
    printf("\nAverage Waiting Time : %f\n",waiting/y);
    printf("---------------------------------------------------------");
    printf("\n\n---------------------------------------------------------");
    printf("\nAverage Turnaround Time : %f\n",turnaround/y);
    printf("---------------------------------------------------------");
    
    return 0;
}
