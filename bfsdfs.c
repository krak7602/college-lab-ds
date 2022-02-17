#include<stdio.h>


void DFS(int);
int G[10][10],visited[10],n;    //n is no of vertices and graph is sorted in array G[10][10]

void dfs_main()
{
    int i,j;
    printf("Enter number of vertices:");
    scanf("%d",&n);

    //read the adjecency matrix
    printf("\nEnter adjecency matrix of the graph:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
 //visited is initialized to zero
    for(i=0;i<n;i++)
        visited[i]=0;

    DFS(1);
}

void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
            DFS(j);
}

int a[20][20],q[20],n,i,j,f=0,r=-1;


void bfs(int v)
{
 for(i=1;i<=n;i++)
  if(a[v][i] && !visited[i])
   q[++r]=i;
 if(f<=r)
 {
  visited[q[f]]=1;
  bfs(q[f++]);
 }
}
void bfs_main()
{
 int v;
 
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  q[i]=0;
  visited[i]=0;
 }
 printf("\n Enter graph data in matrix form:\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 printf("\n Enter the starting vertex:");
 scanf("%d",&v);
bfs(v);
 printf("\n The node which are reachable are:\n");
 for(i=1;i<=n;i++)
  if(visited[i])
   printf("%d\t",i);
  else
   printf("\n Bfs is not possible");
 
}
void main()
{
  int choice;
  printf("\nMenu\n1.DFS\n2.BFS\n3.Exit");
  do
    {
      printf("\nEnter your choice");
      scanf("%d",&choice);
      switch(choice){
        case 1: dfs_main();break;
        case 2: bfs_main();break;
        case 3: printf("\nExiting");break;
        default: printf("\nInvalid choice");
      }
      }while(choice!=3);
}
