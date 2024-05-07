/*A book consists of chapters, chapters consist of sections and sections
consist of subsections. Construct a tree and print the nodes. Find the
time and space requirements of your method.
*/

#include<iostream>
#include<cstring>

using namespace std;
struct node{
    string label;
    node *child[15];
    int cnt;
};
class Book{
public:
    node *root;
    Book()
    {
        root=NULL;
    }
    void create();
    void show();
};
void Book::create()
{
    root=new node;
    cout<<"Enter Name of Book : ";
    cin>>root->label;

    cout<<"Enter No.of Chapters : ";
    cin>>root->cnt;

    for(int i=0;i<root->cnt;i++)
    {
        root->child[i]=new node;
        cout<<"Enter Name of Chapter No :"<<i+1;
        cin>>root->child[i]->label;

        cout<<"Enter No.of Sections : ";
        cin>>root->child[i]->cnt;

        for(int j=0;j<root->child[i]->cnt;j++)
        {
            root->child[i]->child[j]=new node;

            cout<<"Enter the Name of Section :"<<j+1;
            cin>>root->child[i]->child[j]->label;

            cout<<"Enter No of Subsections ";
            cin>>root->child[i]->child[j]->cnt;

            for(int k=0;k<root->child[i]->child[j]->cnt;k++)
            {
                root->child[i]->child[j]->child[k]=new node;

                cout<<"Enter Name of Subsection :"<<k+1;
                cin>>root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}
void Book::show()
{
    if(root==NULL)
        cout<<"Tree is Empty ";
    else{
        cout<<"Book Name:"<<root->label<<endl;
        for(int i=0;i<root->cnt;i++)
        {
            cout<<"\t -CH:"<<i+1<< root->child[i]->label<<endl;
            for(int j=0;j<root->child[i]->cnt;j++)
            {
                cout<<"\t \t -Section "<<j+1<<root->child[i]->child[j]->label<<endl;
                for(int k=0;k<root->child[i]->child[j]->cnt;k++)
                {
                    cout<<"\t \t \t -SubSection "<<k+1<<root->child[i]->child[j]->child[k]->label<<endl;
                }
            }
        }

    }
}
int main()
{
    Book b;
    b.create();
    b.show();
    return 0;
}
