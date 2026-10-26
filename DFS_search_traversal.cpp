#include<iostream>
using namespace std;
int G[20][20], visited[20], n;
void DFS(int i)
{
int j;
cout<<i<<"";

visited[i]=1;
for (j=0;j,n;j++)
{
    if(!visited[j]&&G[i][j]==1)
    DFS(j);

} 
}
int main()
{
    int i,j;
    cout<<"\nEnter the graph of vertices:";
    cin>>n;
    cout<<"\nEnter the adjancency matrix of the graph:\n";
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>G[i][j];
     
    for(i=0;i<n;i++)
    visited[i]=0;
    cout<<"\nDFS traversal is \n";
    DFS(0);

    return 0;
}
/*
output:
PS D:\shruti badhe> cd "d:\shruti badhe\" ; if ($?) { g++ DFS_search_traversal.cpp -o DFS_search_traversal } ; if ($?) { .\DFS_search_traversal }

Enter the graph of vertices:4

Enter the adjancency matrix of the graph:
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

DFS traversal is 
0123
PS D:\shruti badhe> 

 */