#include <stdio.h>
#include <stdlib.h>


struct process_FCFS
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};
struct process_sjf
{
    int pn;
    int bt;
    int at;
    int wt;
    int tt;
};



struct times_rrn
{
    int p,art,but,wtt,tat,rnt;
};


void sortart_rrn(struct times_rrn a[],int pro)
{
    int i,j;
    struct times_rrn temp;
    for(i=0; i<pro; i++)
    {
        for(j=i+1; j<pro; j++)
        {
            if(a[i].art > a[j].art)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return;
}


void print_table_FCFS(struct process_FCFS p[], int n,int arr[],int num);
void print_gantt_chart_FCFS(struct process_FCFS p[], int n,int arr[],int num);
void print_gantt_chart_sjf( struct process_sjf p[], int n);
void print_gantt_chart_priot(int p[], int n, int tat[], int bt[]);

int main()
{
    printf("1.FIRST COME FIRST SERVE\n2.SHORTEST JOB NEXT\n3.PRIORITY SCHEDULING\n4.ROUND ROBBIN\nENTER YOUR CHOISE : ");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
    {
        firstCome();
    }
    if(ch==2)
    {
        shortestJob();
    }
    if(ch==3)
    {
        priority();
    }
    if(ch==4)
    {
        roundRobin();
    }
    return 0;
}

void firstCome()
{
    int MAX_PROCESS=100;
    struct process_FCFS p[MAX_PROCESS];
    //Process p[MAX_PROCESS];
    int i, j, n, temp, total_burst_time;
    int sum_waiting_time = 0, sum_turnaround_time = 0;
    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
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
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
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
    for(i=1; i<n; i++)
    {
        total_burst_time+=p[i].burst_time;
        p[i].turnaround_time = total_burst_time - p[i].arrival_time;
    }

    /// calculate the waiting time
    for(i=0; i<n; i++)
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

}





void print_table_FCFS(struct process_FCFS p[], int n,int arr[],int num)
{
    int i;
    puts("+-----+---------------+------------+--------------+-----------------+");
    puts("| PID |  Arrival Time | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-----+---------------+------------+--------------+-----------------+");

    for(i=0; i<n; i++)
    {
        printf("| p%d  |     %2d        |     %2d     |      %2d      |       %2d        |\n"
               ,arr[i], p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
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





void shortestJob()
{
    int i,n,min,k=1,btime=0;
    int temp,j,ta=0,sum=0;
    float wavg=0,tavg=0,tsum=0,wsum=0;

    printf("\nEnter the No. of processes :");
    scanf("%d",&n);
    struct process_sjf p[n];

    for(i=0; i<n; i++)
    {
        printf("\tEnter the burst time of %d process :",i+1);
        scanf("%d",&p[i].bt);
        printf("\tEnter the arrival time of %d process :",i+1);
        scanf(" %d",&p[i].at);
        p[i].pn=i+1;

    }

    /*Sorting According to Arrival Time*/
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(p[i].at<p[j].at)
            {
                temp=p[j].pn;
                p[j].pn=p[i].pn;
                p[i].pn=temp;
                temp=p[j].at;
                p[j].at=p[i].at;
                p[i].at=temp;
                temp=p[j].bt;
                p[j].bt=p[i].bt;
                p[i].bt=temp;
            }
        }
    }
    /*Arranging the table according to Burst time,
    Execution time and Arrival Time
    Arrival time <= Execution time
    */


    for(j=0; j<n; j++)
    {
        btime=btime+p[j].bt;
        min=p[k].bt;
        for(i=k; i<n; i++)
        {
            if (btime>=p[i].at && p[i].bt<min)
            {
                temp=p[k].pn;
                p[k].pn=p[i].pn;
                p[i].pn=temp;
                temp=p[k].at;
                p[k].at=p[i].at;
                p[i].at=temp;
                temp=p[k].bt;
                p[k].bt=p[i].bt;
                p[i].bt=temp;
            }
        }
        k++;
    }
    p[0].wt=0;
    for(i=1; i<n; i++)
    {
        sum=sum+p[i-1].bt;
        p[i].wt=sum-p[i].at;
        wsum=wsum+p[i].wt;
    }

    wavg=(wsum/n);
    for(i=0; i<n; i++)
    {
        ta=ta+p[i].bt;
        p[i].tt=ta-p[i].at;
        tsum=tsum+p[i].tt;
    }

    tavg=(tsum/n);

    printf("************************");
    printf("\n RESULT:-");
    printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
    for(i=0; i<n; i++)
    {
        printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i].pn,p[i].bt,p[i].at,p[i].wt,p[i].tt);
    }
    printf("\n GANT CHART:-\n");
    print_gantt_chart_sjf(p, n);
    printf("\n\nAVERAGE WAITING TIME : %f",wavg);
    printf("\nAVERAGE TURN AROUND TIME : %f",tavg);

}




void print_gantt_chart_sjf( struct process_sjf p[], int n)
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].bt; j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].bt-1; j++)
            printf(" ");
        printf("P%d", p[i].pn);
        for(j=0; j<p[i].bt- 1; j++)
            printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].bt; j++)
            printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    printf("0");
    for(i=0; i<n; i++)
    {
        for(j=0; j<p[i].bt; j++)
            printf("  ");
        if(p[i].tt > 9)
            printf("\b"); // backspace : remove 1 space
        printf("%d", p[i].tt);

    }
    printf("\n");


}

void priority()
{

    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n");
    for(i=0; i<n; i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }

    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0; i<n; i++)
    {
        pos=i;
        for(j=i+1; j<n; j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0;    //waiting time for first process is zero

    //calculate waiting time
    for(i=1; i<n; i++)
    {
        wt[i]=0;
        for(j=0; j<i; j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=total/n;      //average waiting time
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0; i<n; i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

    printf("*********GANT CHART***********\n");
    print_gantt_chart_priot( p,n,tat,bt);
}



void print_gantt_chart_priot(int p[], int n, int tat[], int bt[])
{

    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<bt[i]; j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");


    // printing process id in the middle
    for(i=0; i<n; i++)
    {

        for(j=0; j<bt[i]-1; j++)
            printf(" ");

        printf("P%d", p[i]);
        for(j=0; j<bt[i]-1; j++)
            printf(" ");
        printf("|");
    }
    printf("\n ");

    // printing bottom bar
    for(i=0; i<n; i++)
    {
        for(j=0; j<bt[i]; j++)
            printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    printf("0");
    for(i=0; i<n; i++)
    {
        for(j=0; j<bt[i]; j++)
            printf("  ");
        if(tat[i] > 9)
            printf("\b"); // backspace : remove 1 space
        printf("%d", tat[i]);

    }
    printf("\n");


}


void roundRobin()
{
    int i,j,pro,time,remain,flag=0,ts;
    struct times_rrn a[100];
    float avgwt=0,avgtt=0;
    printf("Round Robin Scheduling Algorithm\n");
    printf("Note -\n1. Arrival Time of at least on process should be 0\n2. CPU should never be idle\n");
    printf("Enter Number Of Processes : ");
    scanf("%d",&pro);
    remain=pro;
    for(i=0; i<pro; i++)
    {
        printf("Enter arrival time and Burst time for Process P%d : ",i);
        scanf("%d%d",&a[i].art,&a[i].but);
        a[i].p = i;
        a[i].rnt = a[i].but;
    }
    sortart_rrn(a,pro);
    printf("Enter Time Quantum : ");
    scanf("%d",&ts);
    printf("\n***************************************\n");
    printf("Gantt Chart\n");
    printf("0");
    for(time=0,i=0; remain!=0;)
    {
        if(a[i].rnt<=ts && a[i].rnt>0)
        {
            time = time + a[i].rnt;
            printf("--[P%d]--%d",a[i].p,time);
            a[i].rnt=0;
            flag=1;
        }
        else if(a[i].rnt > 0)
        {
            a[i].rnt = a[i].rnt - ts;
            time = time + ts;
            printf("--[P%d]--%d",a[i].p,time);
        }
        if(a[i].rnt==0 && flag==1)
        {
            remain--;
            a[i].tat = time-a[i].art;
            a[i].wtt = time-a[i].art-a[i].but;
            avgwt = avgwt + time-a[i].art-a[i].but;
            avgtt = avgtt + time-a[i].art;
            flag=0;
        }
        if(i==pro-1)
            i=0;
        else if(a[i+1].art <= time)
            i++;
        else
            i=0;
    }
    printf("\n\n");
    printf("***************************************\n");
    printf("Pro\tArTi\tBuTi\tTaTi\tWtTi\n");
    printf("***************************************\n");
    for(i=0; i<pro; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",a[i].p,a[i].art,a[i].but,a[i].tat,a[i].wtt);
    }
    printf("***************************************\n");
    avgwt = avgwt/pro;
    avgtt = avgtt/pro;
    printf("Average Waiting Time : %.2f\n",avgwt);
    printf("Average Turnaround Time : %.2f\n",avgtt);
}
