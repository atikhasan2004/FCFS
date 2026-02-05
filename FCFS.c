#include <stdio.h>
int main()
{
    int n;
    int i;
    int arrival[10],burst[10];
    int completion[10],turnaround[10],waiting[10],response[10];
    int time = 0;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter the Arrival Time of P%d: ",i+1);
        scanf("%d",&arrival[i]);
        printf("Enter the Burst Time of P%d: ",i+1);
        scanf("%d",&burst[i]);
    }
    for (i=0;i<n;i++)
    {
        if (time < arrival[i])
        {
            time=arrival[i];
        }
        //response[i] = time - arrival[i];
        time = time + burst[i];
        completion[i] = time;
        turnaround[i] = completion[i]-arrival[i];
        waiting[i] =turnaround[i] - burst[i]; // Waiting Time = Response Time in the [FCFS]
        response[i] = waiting[i];
    }
    printf("\nProcess\t Arrival_Time\t Burst_Time\t Completion_Time\t Turn_Around_Time\t Waiting_Time\t Response_Time\n");
    for (i=0;i<n;i++)
    {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,arrival[i],burst[i],completion[i],turnaround[i],waiting[i],response[i]);
    }
    return 0;
}
