#include<stdio.h>
struct process
{
    int pid,waiting_time,AT,burst_time,TAT;
};


typedef struct process Process;

void print_gantt_chart(Process p[], int n);

// function for swapping
void swap(int *b,int *c)
{
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}

//Driver function
int main()
{
	Process a[10];
    int n,check_ar=0;
    int Cmp_time=0;
    float Total_WT=0,Total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the Arrival time and Burst time of the process\n");
    printf("arrival time burst time\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].AT,&a[i].burst_time);
        a[i].pid=i+1;
        // here we are checking that arrival time
        // of the process are same or different
        if(i==0)
         check_ar=a[i].AT;

        if(check_ar!=a[i].AT )
         check_ar=1;

    }
    // if process are arrived at the different time
    // then sort the process on the basis of AT
    if(check_ar!=0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(a[j].AT>a[j+1].AT)
                {
                      swap(&a[j].pid,&a[j+1].pid);
                      swap(&a[j].AT,&a[j+1].AT);
                      swap(&a[j].burst_time,&a[j+1].burst_time);
                }
            }
        }
    }

    // logic of SJF non preemptive algo
    // if all the process are arrived at different time
    if(check_ar!=0)
    {
        a[0].waiting_time=a[0].AT;
        a[0].TAT=a[0].burst_time-a[0].AT;
        Cmp_time=a[0].TAT;
        Total_WT=Total_WT+a[0].waiting_time;
        Total_TAT=Total_TAT+a[0].TAT;
        for(int i=1;i<n;i++)
        {
            int min=a[i].burst_time;
            for(int j=i+1;j<n;j++)
            {
                if(min>a[j].burst_time && a[j].AT<=Cmp_time)
                {
                      min=a[j].burst_time;
                      swap(&a[i].pid,&a[j].pid);
                      swap(&a[i].AT,&a[j].AT);
                      swap(&a[i].burst_time,&a[j].burst_time);
                }

            }
            a[i].waiting_time=Cmp_time-a[i].AT;
            Total_WT=Total_WT+a[i].waiting_time;
            // completion time of the process
            Cmp_time=Cmp_time+a[i].burst_time;


            // Turn Around Time of the process
            // compl-Arival
            a[i].TAT=Cmp_time-a[i].AT;
            Total_TAT=Total_TAT+a[i].TAT;

        }
    }



    Avg_WT=Total_WT/n;
    Avg_TAT=Total_TAT/n;


    printf("\nThe process are\n");
    printf("pid arrival time burst time waiting time\tTAT\n");
    for(int i=0;i<n;i++)
    {

        printf("%d\t%d\t\t%d\t%d\t\t%d\t\n",a[i].pid,a[i].AT,a[i].burst_time,a[i].waiting_time,a[i].TAT);

    }
    printf("\nAvg waiting time is:- %f\n",Avg_WT);
    printf("Avg turn around time is:- %f",Avg_TAT);

     printf("\n\nGantt Chart:\n\n");
    print_gantt_chart(a, n);
}

void print_gantt_chart( Process p[], int n)
{


    int i;
    for(i=0;i<n;i++)
    {
        printf("%d     |  ",p[i]);
    }
    printf("\n");

    int Cmp_time=0;
    for(i=0; i<n+1; i++)
    {
        printf("%d\t", Cmp_time);
        Cmp_time=Cmp_time+p[i].burst_time;
    }
}
