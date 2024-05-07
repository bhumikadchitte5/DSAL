/*Read the marks obtained by students of second year in an online
examination of particular subject. Find out maximum and minimum
marks obtained in that subject. Use heap data structure. Analyze the
algorithm. */

#include<iostream>
using namespace std;
class demo{
public:
    int n,arr[10],z;
    void hfy(int i)
    {
        int l,r,m;
        l=2*i+1;
        r=2*i+2;
        m=i;
        if(arr[l]>arr[m] && l<n)
        {
            m=l;
        }
        if(arr[r]>arr[m] && r<n)
        {
            m=r;
        }
        if(i!=m)
        {
            int temp=arr[i];
            arr[i]=arr[m];
            arr[m]=temp;
            hfy(m);
        }
    }
    void create()
    {
        cout<<"Enter No. Of data";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter Data ";
            cin>>arr[i];
        }
        for(int i=(n/2)-1;i>=0;i--)
        {
            hfy(i);
        }
        z=n;
        for(int i=n-1;i>=0;i--)
        {
            int temp=arr[i];
            arr[i]=arr[0];
            arr[0]=temp;
            n--;
            hfy(0);
        }
        for(int i=0;i<z;i++)
        {
            cout<<arr[i];
        }
        cout<<"Min  "<<arr[0]<<"Max  "<<arr[z-1];

    }
};
int main()
{
    demo d;
    d.create();
}
