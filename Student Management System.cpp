#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Abstract
{
public:
    virtual void show()=0;

};
class Add:virtual public Abstract
{
private:
    int due;
    friend class Account;

public:
    static int count;
    char batch[10];
    string name;
    int semester;
    int roll;
    char id[30];
    char bg[10];
    char phone[30];
    char dob[30];
    string address;
    float res;
    Add(){
        strcpy(batch,"CSE_37A");
        semester=8;

        }
    Add(int a)
    {
        strcpy(batch,"CSE_37A");
        semester=a;
    }

    Add(const Add &obj)
    {
        strcpy(batch,obj.batch);
        name = obj.name;
        strcpy(id,obj.id);
        strcpy(bg,obj.bg);
        strcpy(phone,obj.phone);
        strcpy(dob,obj.dob);
        address = obj.address;
        res = obj.res;
        semester = obj.semester;
        roll = obj.roll;
        count = obj.count;
    }
    void get()
    {
        cout<<"\t\t\tEnter Student Name: ";
        cin.ignore();
        getline(cin,name);

        cout<<"\t\t\tEnter Student ID: ";
        cin>>id;

        cout<<"\t\t\tEnter Student roll: ";
        cin>>roll;

        cout<<"\t\t\tEnter Student Date of Birth: ";
        cin>>dob;

        cout<<"\t\t\tEnter Student Blood Group: ";
        cin>>bg;

        cout<<"\t\t\tEnter Student Phone: ";
        cin>>phone;

        cout<<"\t\t\tEnter Student Address: ";
        cin.ignore();
        getline(cin,address);

        cout<<"\t\t\tEnter result CGPA of previous semester: ";
        cin>>res;

        cout<<"\t\t\tEnter Student payable Due for semester(in TK): ";
        cin>>due;
    }
    void show()
    {

        cout<<name<<"\t"<<id<<"\t"<<roll<<"\t"<<dob<<"\t"<<bg<<"\t\t"<<phone<<"\t\t"<<address<<endl;
    }
    void info()const;

    void operator ++(int)
    {
        count=count+1;
    }
};
int Add::count;
void Add::info()const
    {
        cout<<"\t\t******** Department of Computer Science and Engineering **********"<<endl;
        cout<<"\t\t*******************Batch: "<<batch<<"*************\t"<<endl;
        cout<<"\t\t*******************Semester: "<<semester<<"*************\t"<<endl;
        cout<<"\t\t****************Number of Students: "<<count<<"\t\t"<<endl;
    }


class Account:virtual public Add,virtual public Abstract
{
public:
    int pay;
    Account():Add(8){}
    void get(Add &obj)
    {
        name=obj.name;
        roll=obj.roll;
        pay=obj.due;
    }

    void show()
    {

        cout<<"\t"<<name<<"\t"<<roll<<"\t"<<pay<<endl;
    }



};

class Result:public Add
{
public:
    Result():Add(8){}

    void get(Add &objt)
    {
        name=objt.name;
        roll=objt.roll;
        res=objt.res;
    }
    void show()
    {
        cout<<"\t"<<name<<"\t"<<roll<<"\t"<<res<<endl;
    }

};

class Grade:public Add
{
protected:
    float oop,dcom,cg,fs,cgpa;
public:

    Grade():Add(8)
    {
        oop=0;
        dcom=0;
        cg=0;
        cgpa=0;
    }
    void get(Add &object)
    {

        name=object.name;
        roll=object.roll;
        res=object.res;
        cout<<"\t\t\tEnter Grades of roll: "<<roll<<endl;

        cout<<"\t\t\tEnter GPA of Object Oriented Programming: ";
        cin>>oop;

        cout<<"\t\t\tEnter GPA of Data Communications: ";
        cin>>dcom;

        cout<<"\t\t\tEnter GPA of Computational Geometry: ";
        cin>>cg;

        cout<<"\t\t\tEnter GPA of Formal System: ";
        cin>>fs;

        cgpa=(res+((oop+dcom+cg+fs)/6))/2;

        if(oop!=0&&dcom!=0&&cg!=0&&fs!=0)
        object.res=cgpa;

    }

    void print()
    {

        cout<<"\t"<<name<<"\t"<<roll<<"\t"<<oop<<"\t"<<dcom<<"\t"<<cg<<"\t"<<"\t"<<fs<<"\t"<<cgpa<<endl;
    }
};


class Merit
{
    public:
    template<class A,class B>
    void sortclass(A x[],B b)
    {
        int i,j;
        A temp;
        for(i=0;i<b;i++)
        {
            for(j=i+1;j<b;j++)
            {
                if(x[i].res<x[j].res)
                {
                    temp=x[i];
                    x[i]=x[j];
                    x[j]=temp;
                }
            }
        }

        for(i=0;i<b;i++)
        {
            cout<<"\t"<<x[i].name<<"\t"<<x[i].roll<<"\t"<<x[i].res<<endl;
        }
    }
};

class Notice
{
    public:
    void show(int a)
    {
        cout<<"\n\nStudents are requested to pay their dues of this within 05th August"<<endl;
    }

    void show(double a,double b)
    {
        cout<<"\n\nAll the members and staffs are requested to attend the funeral of Mr. Arif Sattar Sir"<<endl;
    }

    void show(char a)
    {
        cout<<"\n\nIt is to inform to all that our university will remain closed from 9th August to 18th August due to the occasion of EID-UL-AZHA"<<endl;
    }
    ~Notice(){};
};


int main()
{
    Add a[20],b[20];
    Account ac[20];
    Result rst[20];
    Grade gd[20];
    char ch;
    int p;
    int m=0,index=-1;
    int choice;
    cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";

        while(1)
        {
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add Student Information";
        cout << "\n \t\t\t 2. List All Student Information";
        cout << "\n \t\t\t 3. Search for a Student";
        cout << "\n \t\t\t 4. Accounts Information";
        cout << "\n \t\t\t 5. View Merit list";
        cout << "\n \t\t\t 6. Add results of current semester";
        cout << "\n \t\t\t 7. Show results of students";
        cout << "\n \t\t\t 8. Notice";

        cout<<"\n\n";
            cout << "\t\t\t Select Your Choice :=> ";
            cin>>choice;
            if(choice<=0||choice>8)
            {
                system("CLS");
                cout<<"\t\t\t INVALID CHOICE !!!!!\n\n"<<endl;
                cout<<"\nPress any key to go back to Homepage...";
                getch();
                system("CLS");

            }


            else
            {

                switch(choice)
                {
                case 1:
                    system("CLS");
                    a[m]++;
                    a[m];
                    a[m].get();
                    m++;
                    system("CLS");
                    break;

                case 2:

                    system("CLS");
                    if(m==0)
                    {
                        cout<<"No records to show ! ! ! !"<<endl;
                        cout<<"\nPress any key to go back to Homepage...";
                        getch();
                        system("CLS");
                    }
                    else
                    {
                        a[m-1].info();

                        for(p=0;p<m;p++)
                        {
                            a[p].show();
                        }
                        cout<<"\n\nPress any key to go back to Homepage...";
                        getch();
                        system("CLS");
                    }
                    break;


                case 3:

                    Abstract *po;
                    int k,item;
                    if(m==0)
                    {
                        system("CLS");
                        cout<<"No records to show ! ! ! !"<<endl;
                        cout<<"\t\tPress any key to go back to Homepage...";
                        getch();
                        system("CLS");
                    }
                    else
                    {
                        system("CLS");
                        cout<<"Enter the Roll you want to search for: ";
                        cin>>item;

                        for(k=0;k<m;k++)
                        {
                            if(a[k].roll==item)
                            {
                                index=k;
                                break;
                            }

                        }
                        if(index==-1)
                        {
                            cout<<"This is is not in the list....!!!!"<<endl;
                            cout<<"\n\nPress any key to go back to Homepage...";
                            getch();
                            system("CLS");
                        }
                        else
                        {
                            po=&a[index];
                            cout<<"\n";
                            po->show();
                            cout<<"\n\nPress any key to go back to Homepage...";
                            getch();
                            system("CLS");
                        }
                    }
                    break;


                case 4:
                    int f;

                    if(m==0)
                    {
                        system("CLS");
                        cout<<"There is no student......"<<endl;
                        cout<<"\n\nPress any key to go back to homepage......";
                        getch();
                        system("CLS");
                    }
                    else
                    {for(f=0;f<m;f++)
                    {
                        ac[f].get(a[f]);
                    }

                    system("CLS");
                    a[m-1].info();


                    for(f=0;f<m;f++)
                    {

                        ac[f].show();
                    }
                    cout<<"\n\nPress any key to go back to Homepage...";
                    getch();
                    system("CLS");
                    }
                    break;


                case 5:
                    Merit mr;
                    int x;

                    if(m==0)
                    {
                        system("CLS");
                        cout<<"There is no student......"<<endl;
                        cout<<"\n\nPress any key to go back to homepage......";
                        getch();
                        system("CLS");

                    }

                    else
                    {


                    for(x=0;x<m;x++)
                    b[x]=a[x];
                    system("CLS");
                    a[m-1].info();
                    mr.sortclass(b,m);

                    cout<<"\n\nPress any key to go back to Homepage...";
                    getch();
                    system("CLS");
                    }

                    break;

                case 6:

                    if(m==0)
                    {
                        system("CLS");
                        cout<<"There is no student......"<<endl;
                        cout<<"\n\nPress any key to go back to homepage......";
                        getch();
                        system("CLS");
                    }

                    else
                    {
                        system("CLS");
                        for(int l=0;l<m;l++)
                        {
                        gd[l].get(a[l]);
                        }
                        a[m-1].info();

                        for(int l=0;l<m;l++)
                        gd[l].print();

                    cout<<"\n\nPress any key to go back to Homepage...";
                    getch();
                    system("CLS");
                    }


                    break;

                case 7:
                    if(m==0)
                    {
                        system("CLS");
                        cout<<"There is no students...."<<endl;
                        cout<<"\n\nPress any key to go back to Homepage...";
                        getch();
                        system("CLS");
                    }

                    else
                    {
                        int h;
                        system("CLS");
                        for(h=0;h<m;h++)
                        {
                            rst[h].get(a[h]);
                        }
                        a[m-1].info();

                        for(h=0;h<m;h++)
                        {
                            rst[h].show();
                        }

                        cout<<"\n\nPress any key to go back to Homepage...";
                        getch();
                        system("CLS");

                    }
                    break;

                case 8:
                system("CLS");
                Notice nt;
                int sc;
                cout<<"Press 1 to view Student Notice."<<endl;
                cout<<"Press 2 to view teacher Notice."<<endl;
                cout<<"Press 3 to view vacation Notice."<<endl;
                cin>>sc;
                try{
                    if(sc<1||sc>3)
                    {
                        throw "Invalid Input!!!!!!!!!!!";

                    }
                if(sc==1)
                {
                    nt.show(10);

                }
                else if(sc==2)
                {
                    nt.show(10.5,20.5);

                }
                else if(sc==3)
                {
                    nt.show('A');
                }
                }
                catch(const char *msg)
                {
                    cout<<msg<<endl;
                }
                cout<<"\n\nPress any key to go back to Homepage...";
                getch();
                system("CLS");
                break;
                }
            }
        }
}
