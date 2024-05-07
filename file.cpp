/*Department maintains a student information. The file contains roll
number, name, division and address. Allow user to add, delete
information of student. Display information of particular student. If
record of student does not exist an appropriate message is
displayed. If it is, then the system displays the student details. Use
sequential file to main the data. */

#include<iostream>
#include<fstream>
using namespace std;
class stud{
public:
    int roll;
    string name;
    char div;
    string add;

    void accept()
    {
        cout<<"Enter Your Roll No.,Name, Division ,Address";
        cin>>roll>>name>>div>>add;
    }
    void show()
    {
        cout<<"Roll No. "<<roll<<endl;
        cout<<"Name "<<name<<endl;
        cout<<"Div "<<div<<endl;
        cout<<"Address"<<add<<endl;
    }
};
int main()
{
    int n,r;
    char c;
    int ch;
    int i;
    int flag=0;
    fstream f;
    cout<<"Enter No. of Students ";
    cin>>n;
    stud s1,s[n];
    do{
        cout<<"1. Insert 2.Show 3.Search 4.Append"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:f.open("t.txt",ios::out);
                for(int i=0;i<n;i++)
                {
                    s[i].accept();
                    f.write((char*)&s[i],sizeof(s[i]));
                }
                f.close();
                break;
            case 2:f.open("t.txt",ios::in);
                i=0;
                while(f.read((char*)&s[i],sizeof(s[i])))
                {
                    s[i].show();
                }
                f.close();
                break;
            case 3:f.open("t.txt",ios::in);
                cout<<"Enter Data to be Search ";
                cin>>r;
                while(f.read((char*)&s[i],sizeof(s[i])))
                {
                    if(s[i].roll==r)
                    {
                        s[i].show();
                        flag=1;
                    }

                }
                if(flag==1)
                    cout<<"Found";
                else
                    cout<<"Not Found";
                f.close();
                break;
            case 4:f.open("t.txt",ios::app);
                    s1.accept();
                    f.write((char*)&s1,sizeof(s1));
                    f.close();
                    break;

        }
        cout<<"Want to Conti(y/n)";
        cin>>c;
    }while(c=='y');

}
