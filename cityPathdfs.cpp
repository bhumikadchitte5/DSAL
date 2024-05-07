/*There are flight paths between cities. If there is a flight between city
A and city B then there is an edge between the cities. The cost of the
edge can be the time that flight takes to reach city B from A or the
amount of fuel used for the journey. Represent this as a graph. The
node can be represented by airport name or name of the city. Use
adjacency list representation of the graph or use adjacency matrix
representation of the graph. Check whether the graph is connected
or not. Justify the storage representation used. */

#include<iostream>
#define MX 10
using namespace std;
int g[MX][MX],visited[MX],n,v;
string a[MX];
int dfs(int );
int main()
{
    cout<<"No.of Nodes ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter City";
        cin>>a[i];
    }
    cout<<"Enter 0/1";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(i==j)
            {
                g[i][j]=0;
                continue;
            }
            cout<<"Enter cost"<<a[i]<<"--"<<a[j];
            cin>>g[i][j];
            g[j][i]=g[i][j];
        }
    }
    cout<<"Start";
    cin>>v;
    dfs(v);
}
int dfs(int v)
{
    cout<<a[v]<<"  ";
    visited[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(g[v][i]==1 && visited[i]!=1)
        {
            dfs(i);
        }
    }

}
