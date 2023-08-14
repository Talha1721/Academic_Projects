#include<stdio.h>
#define INFINITY 99
#define MAX 100
void dijkstra(int n,int startnode);
int G[MAX][MAX];
int main(){
	int i,j,n, u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(n,u);
	return 0;
}
void dijkstra(int n, int startnode){
	int distance[MAX],pre[MAX];
	int visited[MAX]={0},count,mindistance,nextnode,i,j;
	for(i=0;i<n;i++){
		pre[i]=startnode;
		distance[i]=G[startnode][i];
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1){
		mindistance=INFINITY;
		for(i=0;i<n;i++){
			if(distance[i]<mindistance&&visited[i]==0){
				mindistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;
		for(i=0;i<n;i++){
			if(visited[i]==0){
				if(mindistance+G[nextnode][i]<distance[i]){
					distance[i]=mindistance+G[nextnode][i];
					pre[i]=nextnode;
				}
			}
		}
		count++;
	}
	for(i=0;i<n;i++){
		if(i!=startnode){
			printf("\nDistance of node%c=%c",i+65,distance[i]+65);
			printf("\nPath=%c",i+65);
			j=i;
			do{
			  	j=pre[j];
				printf(" <- %c",j+65);
			}
			while(j!=startnode);
		}
	}
}
