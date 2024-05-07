/*A Dictionary stores keywords & its meanings. Provide facility for
adding new keywords, deleting keywords. Provide facility to
display whole data sorted in ascending/ Descending order. Also
find how many maximum comparisons may require for finding any
keyword. Use Height balance tree and find the complexity for
finding a keyword. (Insert, delete,search,update, display)*/

#include<iostream>
#include<string.h>
using namespace std;
struct node{
    char word[10],mean[10];
    node *left, *right;
    int ht;
};
class dict{
public:
    node* create(node *root)
    {
        char w[10],m[10];
        int n;
        cout<<"Enter no. of Words ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter Word and meaning";
            cin>>w>>m;
            root=add(root,w,m);
        }
        return root;
    }
    node* add(node *root,char w[],char m[])
    {
        if(root==NULL)
        {
            root=new node;
            strcpy(root->word,w);
            strcpy(root->mean,m);
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        else if(strcmp(w,root->word)>0)
        {
            root->right=add(root->right,w,m);
            if(bf(root)==-2)
            {
                if(strcmp(w,root->word)>0)
                {
                    root=RR(root);
                }
                else{
                    root=RL(root);
                }
            }
        }
        else if(strcmp(w,root->word)<0)
        {
            root->left=add(root->left,w,m);
            if(bf(root)==2)
            {
                if(strcmp(w,root->word)<0)
                {
                    root=LL(root);
                }
                else{
                    root=LR(root);
                }
            }
        }
        root->ht=height(root);
        return root;
    }
    int height(node *root)
    {
        int l,r;
        if(root==NULL)
            return 0;
        if(root->left==NULL)
            l=0;
        else
            l=1+root->left->ht;
        if(root->right==NULL)
            r=0;
        else
            r=1+root->right->ht;
        if(l>r)
            return (l);
        else
            return(r);

    }
    int bf(node *root)
    {
        int l,r;
        if(root==NULL)
            return 0;
        if(root->left==NULL)
            l=0;
        else
            l=1+root->left->ht;
        if(root->right==NULL)
            r=0;
        else
            r=1+root->right->ht;
        int z=l-r;
        return z;
    }
    node* rLeft(node *x)
    {
        node *y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->ht=height(x);
        y->ht=height(y);
        return (y);
    }
    node* rRight(node *x)
    {
        node *y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->ht=height(x);
        y->ht=height(y);
        return (y);
    }
    node* RR(node *T)
    {
        T=rLeft(T);
        return (T);
    }
    node* LL(node *T)
    {
        T=rRight(T);
        return (T);
    }
    node* RL(node *T)
    {
        T->right=rRight(T->right);
        T=rLeft(T);
        return(T);
    }
    node* LR(node *T)
    {
        T->left=rLeft(T->left);
        T=rRight(T);
        return (T);
    }
    void show(node *root)
    {

        if(root!=NULL)
        {
            cout<<"Left"<<endl;
            show(root->left);
            cout<<root->word<<"--"<<root->mean<<endl;
            cout<<"Right"<<endl;
            show(root->right);
        }
    }
    node* search(node *root,char w[])
    {
        if(root==NULL)
            return NULL;
        else{
            if(strcmp(w,root->word)==0)
                return root;
            else if(strcmp(w,root->word)>0)
                return search(root->right,w);
            else if(strcmp(w,root->word)<0)
                return search(root->left,w);
        }
    }
    node* del(node *root ,char w[])
    {
        node *p;
        if(root==NULL)
            return root;
        else if(strcmp(w,root->word)>0)
        {
            root->right=del(root->right,w);
            if(bf(root)==2)
            {
                if(bf(root->left)>=0)
                    root=LL(root);
                else
                    root=LR(root);
            }
        }
        else if(strcmp(w,root->word)<0)
        {
            root->left=del(root->left,w);
            if(bf(root)==-2)
            {
                if(bf(root->right)<=0)
                    root=RR(root);
                else
                    root=RL(root);
            }

        }
        else{
            p=root->right;
            if(root->right!=NULL){
                while(p->left!=NULL)
                    p=p->left;
                strcpy(root->word,p->word);
                strcpy(root->mean,p->mean);
                root->right=del(root->right,root->word);
                if(bf(root)==2)
                {
                    if(bf(root->left)>=0)
                        root=LL(root);
                    else
                        root=LR(root);
                }
            }
            else
                return(root->left);

        }
        root->ht=height(root);
            return(root);
    }
    node* up(node *root,char w[],char nm[])
    {
        root=del(root,w);
        root=add(root,w,nm);
        return root;
    }
};
int main()
{
    dict d;
    node *root=NULL;
    node *t=NULL;
    char w[10],m[10];
    char c;
    do{
        int ch;
        cout<<" 1 Create 2.Insert 3.show";
        cin>>ch;
        switch(ch){
            case 1:
                root=d.create(root);
                break;
            case 2:
                cout<<"Enter Word & Mean ";
                cin>>w>>m;
                root=d.add(root,w,m);
                break;
            case 3:
                d.show(root);
                break;
            case 4:
                cout<<"Enter Word";
                cin>>w;
                t=d.search(root,w);
                if(t==NULL)
                    cout<<"Not Found";
                else
                    cout<<" Found";
                break;
            case 5:
                cout<<"Enter Word";
                cin>>w;
                root=d.del(root,w);
                break;
            case 6:
                cout<<"Enter Word & Mean ";
                cin>>w>>m;
                root=d.up(root,w,m);
                break;
            default:
                cout<<"Wrong ";
        }
        cout<<"Do you want to Conti ";
        cin>>c;
    }while(c=='y');
}
