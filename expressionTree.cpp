/*Construct an expression tree from the given prefix expression eg. +-
-a*bc/def and traverse it using post order traversal (non-recursive)
and then delete the entire tree. */

#include<iostream>
#include<cstring>
#define MX 10
using namespace std;
struct node{
    char data;
    node *left, *right;
};
node *root;
class cStack{
public:
    int top;
    node *stk[MX];
    cStack()
    {
        top=-1;
    }
    int isFull()
    {
        if(top==MX)
            return 1;
        else
            return 0;
    }
    int isEmpty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    void push(node *e)
    {
        if(isFull())
        {
            cout<<"Full";
        }
        else{
            top++;
            stk[top]=e;
        }
    }
    node* pop()
    {
        if(isEmpty())
        {
            cout<<"Empty";
        }
        else{
            node *t;
            t=stk[top];
            top--;
            return(t);
        }
    }
};
class eTree{
public:
    void create()
    {
        cStack s;
        node *top;
        char pre[20];
        cout<<"Enter Prefix Expression ";
        cin>>pre;
        int len=strlen(pre);
        for(int i=len;i>=0;i--)
        {
            top=new node;
            top->left=nullptr;
            top->right=NULL;
            if(isalpha(pre[i]))
            {
                top->data=pre[i];
                s.push(top);
            }
            else if(pre[i]=='+' ||pre[i]=='-' ||pre[i]=='*' ||pre[i]=='/' )
            {
                node *t1, *t2;
                t1=s.pop();
                t2=s.pop();

                top->data=pre[i];
                top->left=t1;
                top->right=t2;
                s.push(top);
            }
        }
        root=s.pop();
    }
    void postOrd(node *t)
    {
        cStack s1,s2;
        node *t1,*t2;
        t1=t;
        s1.push(t1);
        while(!s1.isEmpty())
        {
            t1=s1.pop();
            s2.push(t1);
            if(t1->left!=NULL)
                s1.push(t1->left);
            if(t1->right!=NULL)
                s1.push(t1->right);
        }
        while(!s2.isEmpty())
        {
            t2=s2.pop();
            cout<<t2->data;
        }
    }
    void del(node *t)
    {
        if(t!=NULL)
        {   del(t->left);
            del(t->right);
            cout<<t->data;
            delete(t);
        }

    }
};
int main()
{
    eTree e;
    e.create();
    e.postOrd(root);
    e.del(root);
    return 0;
}
