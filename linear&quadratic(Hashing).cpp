/*Implement all the functions of a dictionary (ADT) using hashing
and handle collisions using closed addressing: with replacement:
Data: Set of (key, value) pairs, Keys are mapped to values, Keys
must be comparable, Keys must be unique.
Standard Operations: Insert(key, value), Find(key), Delete(key)*/

#include<iostream>
#include<string.h>
#define MX 10
using namespace std;
struct node{
    char name[10];
    long int tel;
    node(){
        tel=0;
        strcpy(name,"---");
    }
};
class telephone{
public:
    node hl[MX];
    node hq[MX];
    int hf(long int mn)
    {
        return(mn%MX);
    }
    void insertl()
    {
        node s;
        int ind;
        cout<<"Enter your Name & Mobile No.";
        cin>>s.name>>s.tel;
        ind=hf(s.tel);
        cout<<ind;
        if(hl[ind].tel==0)
        {
            hl[ind]=s;
        }
        else{
            while(hl[ind].tel!=0)
            {
                ind=(ind+1)%MX;

            }
            cout<<"New Index: "<<ind;
            hl[ind]=s;
        }
    }
    void display()
    {
        for(int i=0;i<MX;i++)
        {
            cout<<hl[i].name<<"\t"<<hl[i].tel<<endl;
        }
    }
    void insertq()
    {
        node s;
        int ind;
        int long m;
        cout<<"Enter your Name & Mobile ";
        cin>>s.name>>s.tel;
        m=s.tel;
        ind=hf(s.tel);
        cout<<ind;
        if(hq[ind].tel==0)
        {
            hq[ind]=s;
        }
        else{
            int i=1;
            while(hq[ind].tel!=0)
            {
                ind=(m+i*i);
                ind=ind%MX;
                i++;
            }
            cout<<"New Ind "<<ind;
            hq[ind]=s;
        }
    }
    void displayq()
    {
        for(int i=0;i<MX;i++)
        {
            cout<<hq[i].name<<"\t"<<hq[i].tel<<endl;
        }
    }

    void search()
    {
        int flag=0;
        long int m;
        int ind;
        cout<<"Enter your Mobile No.";
        cin>>m;
        ind=hf(m);
        for(int i=0;i<MX;i++)
        {
            if(hl[ind].tel==m)
            {
                cout<<hl[ind].name<<"\t"<<hl[ind].tel;
                flag=1;
                break;
            }
            ind=(ind+1)%MX;
        }
        if(flag==0)
            cout<<"Not Found";
    }
    void qsearch()
    {
        int long m;
        int flag=0;
        cout<<"Enter No.";
        cin>>m;
        int ind=hf(m);
        int q=1;
        for(int i=0;i<MX;i++)
        {
            if(hq[ind].tel==m)
            {
                /*cout<<hq[ind].tel<<"\t"<<hq[ind].name;
                flag=1;*/
                break;
            }
            ind=(ind+(q*q))%MX;
            q++;
        }
        if(flag==0)
            cout<<"Not Found";

    }

};
int main()
{
    telephone t;
    char c;
    do{
        cout<<"\n 1.InsertL \n 2.Display \n 3 Insertq \n Displayq";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                 t.insertl();
                break;
            case 2:
                t.display();
                break;
            case 3:
                 t.insertq();
                break;
            case 4:
                t.displayq();
                break;
            case 5:
                t.search();
                break;
            case 6:
                t.qsearch();
                break;
            default:
                cout<<"Wrong ";

        }
        cout<<"Want to Conti...(y/n)";
        cin>>c;
    }while(c=='y');
    return 0;
}
