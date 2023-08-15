#include<stdio.h>

struct process_sjf
{
    int pn;
    int bt;
    int at;
    int wt;
    int tt;
};
int main()
{



int i,n,min,k=1,btime=0;
int temp,j,ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf(" -------Shortest Job First Scheduling ( NP )-------\n");
printf("\nEnter the No. of processes :");
scanf("%d",&n);
struct process_sjf p[n];

for(i=0;i<n;i++)
{
printf("\tEnter the burst time of %d process :",i+1);
scanf("%d",&p[i].bt);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&p[i].at);
p[i].pn=i+1;

}

/*Sorting According to Arrival Time*/
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
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


for(j=0;j<n;j++)
{
btime=btime+p[j].bt;
min=p[k].bt;
for(i=k;i<n;i++)
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
for(i=1;i<n;i++)
{
sum=sum+p[i-1].bt;
p[i].wt=sum-p[i].at;
wsum=wsum+p[i].wt;
}

wavg=(wsum/n);
for(i=0;i<n;i++)
{
ta=ta+p[i].bt;
p[i].tt=ta-p[i].at;
tsum=tsum+p[i].tt;
}

tavg=(tsum/n);

printf("************************");
printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i].pn,p[i].bt,p[i].at,p[i].wt,p[i].tt);
}
 printf("\n GANT CHART:-\n");
  print_gantt_chart_sjf(p, n);
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
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
