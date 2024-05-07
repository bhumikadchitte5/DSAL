/*Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client‘s telephone number.
Make use of Linear & quadratic probing(without replacement) and
compare them using number of comparisons required to find a set
of telephone numbers
*/

#include<iostream>
#include<string.h>
#define MX 10
using namespace std;
struct node{
    char name[10];
    long int mn;
    int chain;
    node()
    {
        mn=0;
        chain=-1;
        strcpy(name,"---");
    }
};

class tel{
public:
    node ht[MX];
    int hf(long int m)
    {
        return(m%MX);
    }
    void add()
    {
        node s;
        cout<<"Enter data";
        cin>>s.name>>s.mn;

        int ind=hf(s.mn);
        if(ht[ind].mn==0)
        {
            ht[ind]=s;
        }
        else if(ind==hf(ht[ind].mn))
        {
            int prev=ind;
            while(ht[ind].mn!=0)
            {
                prev=ind;
                ind=(ind+1)%MX;
            }
            ht[ind]=s;
            ht[prev].chain=ind;
        }
        else{
            node r=ht[ind];
            ht[ind]=s;
            while(ht[ind].mn!=0)
            {
                ind=(ind+1)%MX;
            }
            ht[ind]=r;
            int x=hf(r.mn);
            int o=x;
            while(ht[x].chain!=-1)
            {
                x=ht[x].chain;
                if(ht[x].chain!=-1)
                    o=x;
            }
            if(hf(ht[x].mn)==o)
            {
                ht[x].chain=ind;
            }
            else{
                ht[o].chain=ind;
            }
        }
    }
    void show()
    {
        for(int i=0;i<MX;i++)
        {
            cout<<ht[i].name<<"  "<<ht[i].mn<<"  "<<ht[i].chain<<endl;
        }
    }
    void srch()
    {
        long int m;
        cin>>m;
        int ind=hf(m);
        int start=ind;
        while(start!=-1 && ht[start].mn!=m)
        {
            start=ht[start].chain;
        }
        if(start==-1)
            cout<<"N";
        else
            cout<<"F";

    }
    void del()
    {
       long int num;
       cin>>num;
       int ind=hf(num);
       int start=ind;
       int prev=-1;
       while(start!=-1 && ht[start].mn!=num)
       {
           prev=start;
           start=ht[start].chain;
       }
       if(start==-1)
            cout<<"N";
       else{
            if(prev!=-1)
                ht[prev].chain=ht[start].chain;
            else
                ht[ind]=node();
            cout<<"Deleted";

       }

        /*long int num;
        cout << "Enter telephone number to delete: ";
        cin >> num;
        int ind = hf(num);
        int start = ind;
        int prev = -1;
        while (start != -1 && ht[start].mn != num) {
            prev = start;
            start = ht[start].chain;
        }
        if (start == -1)
            cout << "Number not found." << endl;
        else {
            if (prev != -1)
                ht[prev].chain = ht[start].chain;
            else
                ht[ind] = node();
            cout << "Number deleted." << endl;
        }*/
    }

};
int main()
{
    tel t;
    int ch;
    do{
        cin>>ch;
        switch(ch)
        {
            case 1:
                 t.add();
                break;
            case 2:
                t.show();
                break;
            case 3:
                t.srch();
                break;
            case 4:
                t.del();
                break;

        }
    }while(ch!=5);
    return 0;
}
