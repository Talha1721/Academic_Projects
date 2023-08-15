#include<stdio.h>

struct process_FCFS
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};


void print_table_FCFS(struct process_FCFS p[], int n,int arr[],int num);
void print_gantt_chart_FCFS(struct process_FCFS p[], int n,int arr[],int num);

int main()
{
    int MAX_PROCESS=100;
    struct process_FCFS p[MAX_PROCESS];
    //Process p[MAX_PROCESS];
    int i, j, n, temp, total_burst_time;
    int sum_waiting_time = 0, sum_turnaround_time = 0;
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    /// array will be initialized for process id;
    int num=10;
    printf("Enter total number of process: ");
    scanf("%d", &n);
    printf("\n");
    printf("Enter burst time and arrival time for each process:\n");
    printf("\n");
    for(i=0; i<n; i++)
    {
        p[i].pid = i+1;
        printf("For P%d Process  ", i+1);
        printf("\nBurst Time  :");
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time:");
        scanf("%d",&p[i].arrival_time);
        p[i].waiting_time =  0;
        p[i].turnaround_time = 0;
        p[i].completion_time = 0;
        printf("\n");
    }
    /// sorting using arrival time
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].arrival_time > p[j].arrival_time)
            {
                temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;

                temp = p[j].arrival_time;
                p[j].arrival_time = p[i].arrival_time;
                p[i].arrival_time = temp;

                temp = p[j].burst_time;
                p[j].burst_time = p[i].burst_time;
                p[i].burst_time = temp;
            }
        }
    }

    /// calculating the turnaround time
    p[0].turnaround_time = p[0].burst_time;
    total_burst_time = p[0].burst_time;
    for(i=1;i<n;i++)
    {
        total_burst_time+=p[i].burst_time;
        p[i].turnaround_time = total_burst_time - p[i].arrival_time;
    }

    /// calculate the waiting time
    for(i=0;i<n;i++)
    {
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }

    /// calculate sum of waiting time and sum of turnaround time
    for(i=0; i<n; i++)
    {
            sum_waiting_time = sum_waiting_time + p[i].waiting_time;
            sum_turnaround_time = sum_turnaround_time + p[i].turnaround_time;
    }

    puts("");
    printf("The Result Table for FCFS:");
    puts("");
    print_table_FCFS(p,n,arr,num);
    puts("");

    printf("Total Waiting Time      : %2d\n", sum_waiting_time);
    printf("Average Waiting Time    : %2.2lf\n", (double)sum_waiting_time / (double) n);
    printf("Total Turnaround Time   : %2d\n", sum_turnaround_time);
    printf("Average Turnaround Time : %2.2lf\n", (double)sum_turnaround_time / (double) n);

    puts("");
    puts("GANTT CHART:");
    print_gantt_chart_FCFS(p,n,arr,num);
    puts("");
    return 0;
}

void print_table_FCFS(struct process_FCFS p[], int n,int arr[],int num)
{
    int i;
    puts("+-----+---------------+------------+--------------+-----------------+");
    puts("| PID |  Arrival Time | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-----+---------------+------------+--------------+-----------------+");

    for(i=0;i<n;i++)
    {
        printf("| p%d  |     %2d        |     %2d     |      %2d      |       %2d        |\n"
               ,arr[i] , p[i].arrival_time , p[i].burst_time , p[i].waiting_time , p[i].turnaround_time);
        puts("+-----+---------------+------------+--------------+-----------------+");
    }
}

void print_gantt_chart_FCFS(struct process_FCFS p[], int n,int arr[],int num)
{
    int i, j,sum = 0;
    /// print top bar
    printf(" ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].burst_time; j++)
        {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");

    /// printing process id in the middle
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].burst_time - 1; j++)
        {
            printf(" ");
        }
        printf("P%d", arr[i]);
        for(j=0; j<p[i].burst_time - 1; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    /// printing bottom bar
    printf("\n ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].burst_time; j++)
        {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    /// printing the time line
    printf("0");
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].burst_time; j++)
        {
            printf("  ");
        }
        sum = sum + p[i].burst_time;
        if( sum  > 9)
        {
            printf("\b"); /// if the number is greater than 9 then remove 1 space
        }
        printf("%d", sum);
    }
    printf("\n");
}
