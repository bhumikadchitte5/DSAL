/*Beginning with an empty binary search tree, Construct binary
search tree by inserting the values in the order given. After
constructing a binary tree -
 i. Insert new node
 ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv Search a specific value in a tree
v. Change a tree so that the roles of the left and right pointers are
swapped at every
 node (Mirror image)*/

#include<iostream>
using namespace std;
struct node{
    int data;
    node *left ,*right;
};
node *root;
class tree{
public:
    int flag=0;
    tree(){
        root=NULL;
    }
    void create()
    {
        char c;
        do{
            node *nn;
            nn=new node;
            nn->left=NULL;
            nn->right=NULL;
            cout<<"Enter Data";
            cin>>nn->data;

            if(root==NULL)
            {
                root=nn;
            }
            else{
                add(root, nn);
            }
            cout<<"Do you Want to Continue ";
            cin>>c;

        }while(c=='y');
    }
    void add(node *root, node *nn)
    {
        if(root->data>nn->data)
        {
            if(root->left==NULL)
                root->left=nn;
            else
                add(root->left,nn);
        }
        else if(root->data<nn->data)
        {
            if(root->right==NULL)
                root->right=nn;
            else
                add(root->right,nn);
        }
    }
    void show(node *root)
    {
        if(root!=NULL)
        {
            show(root->left);
            cout<<root->data;
            show(root->right);
        }
    }
    node* search(node *root,int key)
    {
        if(root==NULL)
            cout<<"Empty";
        else{
            if(root->data==key)
            {
                flag=1;

            }
            else if(root->data>key)
            {
                return search(root->left,key);
            }
            else if(root->data<key)
            {
                return search(root->right,key);
            }
        }


        if(flag==1)
            cout<<"Found";
        else
            cout<<"Not Found ";

    }
    void min(node *root)
    {
        node *temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        cout<<"\n Min="<<temp->data;
    }
    void mir(node *root)
    {
        if(root!=NULL)
          {
                node *temp;
                temp=root->left;
                root->left=root->right;
                root->right=temp;
                mir(root->left);
                mir(root->right);
          }

    }
    int dep(node *root)
    {
        if(root==NULL)
            return 0;
        else{
            int l,r;
            l=dep(root->left);
            r=dep(root->right);
            if(l>r)
                return(l+1);
            else
                return (r+1);
        }
    }
    int lng(node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        else{
            int lh,rh;
            lh=dep(root);
            rh=dep(root);
            if(lh>rh)
                cout<<"Nodes :"<<lh+1;
            else
                cout<<"Nodes :"<<rh+1;
        }
    }
};
int main()
{
    tree t;
    t.create();
    t.show(root);
    int k;
    cout<<"Data to be search ";
    cin>>k;
    t.search(root,k);
    t.min(root);
    t.mir(root);
    t.show(root);
    t.lng(root);

    return 0;
}
