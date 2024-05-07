
/*Represent a given graph using adjacency matrix & perform DFS in
recursive & non-recursive method. */
#include<iostream>
#include<stack>
using namespace std;
int n,visited[5],g[5][5],v;
int dfs(int);
int main()
{
    cout<<"Enter no. of nodes";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    cout<<"Enter starting node ";
    cin>>v;
    dfs(v);
}
int dfs(int v)
{
    //Non Recursive
    stack<int> stk;
    stk.push(v);
    while(!stk.empty())
    {
        v=stk.top();
        stk.pop();
        if(visited[v]==0)
        {
            cout<<v<<" ";
            visited[v]=1;
            for(int i=1;i<=n;i++)
            {
                if(g[v][i]==1)
                {
                    stk.push(i);
                }
            }
        }
    }
    //Recursive Code
    cout<<v;
    visited[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(g[v][i]==1 && visited[i]!=1)
        {
            dfs(i);
        }
    }
