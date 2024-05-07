/*Given sequence k = k1 <k2 < … < kn of n sorted keys, with a search
probability pi for each key ki . Build the Binary search tree that has
the least search cost given the access probability for each key.
*/

#include<iostream>
#include<queue>
#define MX 10
using namespace std;
class obst{
public:
    int w[MX][MX],r[MX][MX],c[MX][MX],a[MX],p[MX],q[MX];
    int n;
    void accept()
    {
        cout<<"Enter No. of data";
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cout<<"enter data ";
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cout<<"Suc Prob ";
            cin>>p[i];
        }
        for(int i=0;i<=n;i++)
        {
            cout<<"unSuc Prob ";
            cin>>q[i];
        }
    }
    int find(int i,int j)
    {
        int k,m,mn;
        mn=2000;
        for(k=i+1;k<=j;k++)
        {
            if((c[i][k-1]+c[k][j])<mn)
            {
                mn=c[i][k-1]+c[k][j];
                m=k;
            }
        }
        return m;
    }
    void build()
    {
        for(int i=0;i<n;i++)
        {
            w[i][i]=q[i];
            c[i][i]=r[i][i]=0;
        }
        for(int i=0;i<n;i++)
        {
            w[i][i+1]=q[i+1]+p[i+1]+w[i][i];
            c[i][i+1]=w[i][i+1];
            r[i][i+1]=i+1;
        }
        for(int m=2;m<=n;m++)
        {
            for(int i=0;i<=n-m;i++)
            {
                int j=m+i;
                w[i][j]=p[j]+q[j]+w[i][j-1];
                int k=find(i,j);
                c[i][j]=c[i][k-1]+c[k][j]+w[i][j];
                r[i][j]=k;
            }
        }
    }
    void show()
    {
        queue<int> q;
        cout<<"Root="<<r[0][n]<<endl;
        q.push(0);
        q.push(n);
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            int j=q.front();
            q.pop();
            int k=r[i][j];
            cout<<"    "<<k<<endl;
            if(r[i][k-1]!=0)
            {
                cout<<" "<<r[i][k-1];
                q.push(i);
                q.push(k-1);
            }
            else
                cout<<"     "<<endl;
            if(r[k][j]!=0)
            {
                cout<<"     "<<r[k][j];
                q.push(k);
                q.push(j);
            }
            else
                cout<<"     "<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    obst o;
    o.accept();
    o.build();
    o.show();
    return 0;
}
