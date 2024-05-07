/*Implement all the functions of a dictionary (ADT) using hashing
and handle collisions using open addressing method (implement
using linked list).
Data: Set of (key, value) pairs, Keys are mapped to values, Keys
must be comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)*/

#include<iostream>
#include<string.h>
#define MX 10
using namespace std;
struct node{
    char name[10];
    long int mn;
    node *next;
};
class  demo{
public:
    node *arr[MX];
    demo()
    {
        for(int i=0;i<MX;i++)
        {
            arr[i]=NULL;
        }
    }
    int hf(long int m)
    {
        return(m%MX);
    }
    void add()
    {
        node *nn;
        nn=new node;
        cout<<"Enter name & no";
        cin>>nn->name>>nn->mn;
        nn->next=NULL;
        int ind=hf(nn->mn);
        cout<<ind;
        if(arr[ind]==NULL)
        {
            arr[ind]=nn;
        }
        else{
            while(arr[ind]!=NULL)
            {
                ind=(ind+1)%MX;
            }
            cout<<ind;
            arr[ind]=nn;
        }
    }
    void show()
    {
        node *t;
        for(int i=0;i<MX;i++)
        {
            cout<<endl<<"Index: "<<i;
            t=arr[i];
            while(t!=NULL)
            {
                cout<<t->name<<"--"<<t->mn;
                t=t->next;
            }
        }
    }
    void srch()
    {
        node *t;
        long int m;
        cin>>m;
        int flag=0;
        int ind=hf(m);

        for(int i=0;i<MX;i++)
        {
            t=arr[ind];
            while(t!=NULL)
            {
                if(t->mn==m)
                    flag=1;
                    break;
                t=t->next;
                if(t->mn==m)
                    arr[ind]=NULL;
                t=t->next;
            }
            ind=(ind+1)%MX;
        }


       if(flag==1)
            cout<<"F";
        else
            cout<<"N";
    }

};
int main()
{
    demo d;
    char c;
    do{
        cout<<"1.add 2.show ";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                d.add();
                break;
            case 2:
                d.show();
                break;
            case 3:
                d.srch();
                break;
            default:
                cout<<"wrong";
        }
        cout<<"Coti";
        cin>>c;
    }while(c=='y');
}
