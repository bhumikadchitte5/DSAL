/*Represent a given graph using adjacency list to perform BFS. Use
non-recursive method */
#include<iostream>
#define MX 10
using namespace std;
int visited[MX],n,y,v;
struct node{
    int data;
    node *next;
};
node *adj[MX];
int bfs(int);
int main()
{
    cout<<"Enter no.of Nodes";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        adj[i]=NULL;
    }
     for(int m=1;m<=n;m++)
    {
        visited[m]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>y;

           if(y==1)
            {
                node *nn, *temp;
                nn=new node;
                nn->data=j;
                nn->next=NULL;
                if(adj[i]==NULL)
                {
                    adj[i]=nn;
                }
                else{
                    temp=adj[i];
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=nn;
                }
            }

        }
    }
    cout<<"Enter Starting Point ";
    cin>>v;
    bfs(v);
    return 0;
}
int bfs(int v)
{
    int que[MX], f,r;
    f=0;
    r=0;
    que[r]=v;
    r++;
    cout<<v;
    visited[v]=1;
    while(f!=r)
    {
        int c;
        c=que[f];
        f++;
        node *temp;
        temp=adj[c];
        while(temp!=NULL)
        {
            if(visited[temp->data]!=1)
            {
                cout<<temp->data;
                visited[temp->data]=1;
                que[r]=temp->data;
                r++;
            }
            temp=temp->next;
        }
    }
}
