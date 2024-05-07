/*There are flight paths between cities. If there is a flight between city
A and city B then there is an edge between the cities. The cost of the
edge can be the time that flight takes to reach city B from A or the
amount of fuel used for the journey. Represent this as a graph. The
node can be represented by airport name or name of the city. Use
adjacency list representation of the graph or use adjacency matrix
representation of the graph. Check whether the graph is connected
or not. Justify the storage representation used. */

#include<iostream>
#include<queue>
#define MX 10
using namespace std;
int g[MX][MX],visited[MX],n;
class demo{
public:
    string a[MX],s,d,name;
    int r,c,cst;
    char ch;
    int cnt=0;
    void acc(){
            cout<<"NO f cities";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    g[i][j]=0;
                }
            }
            for(int i=0;i<n;i++)
            {
                visited[i]=0;
            }
            for(int i=0;i<n;i++)
            {
                cout<<" cities";
                cin>>name;
                a[i]=name;
            }
            do{
                cout<<"S cities";
                cin>>s;
                cout<<"D cities";
                cin>>d;
                for(int i=0;i<n;i++)
                {
                    if(a[i]==s)
                    {
                        r=i;
                        break;
                    }
                }
                for(int i=0;i<n;i++)
                {
                    if(a[i]==d)
                    {
                        c=i;
                        break;
                    }
                }
                cout<<"Cost";
                cin>>cst;
                g[r][c]=cst;
                g[c][r]=cst;

                cout<<"Cont";
                cin>>ch;

            }while(ch=='y');
    }
    void bfs()
    {
        queue<int>q;
        q.push(0);
        visited[0]=1;
        cnt++;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            cout<<a[v]<<"\t";
            for(int i=0;i<n;i++)
            {
                if(g[v][i]!=0)
                {
                    if(visited[i]==0)
                    {
                        q.push(i);
                        visited[i]=1;
                        cnt++;
                    }
                }
            }
        }
        if(cnt==n)
            cout<<"C";
        else
        {
            cout<<"nC";
        }
    }

};
int main()
{
    demo d;
    d.acc();
    d.bfs();
    return 0;
}
