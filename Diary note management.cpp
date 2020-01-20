#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Element
{
    string title;
    string day;
    string month;
    string year;
    string des;
    Element *next;
};
struct list
{
    int n;
    Element *head;
    Element *tail;
};
void add(list *ls, string title,string day,string month,string year,string des)
{
    Element *e;
    e=new Element;
    e->next=NULL;
    e->title=title;
    e->day=day;
    e->month=month;
    e->year=year;
    e->des=des;
    if(ls->n==0)
    {
        ls->head=e;
        ls->tail=e;
        ls->n=ls->n+1;
    }else
    {
        ls->tail->next=e;
        ls->tail=e;
        ls->n=ls->n+1;
    }
}
void display(list *ls)
{
    Element *t;
    t=ls->head;
    int num=0;
    while(t!=NULL)
    {
        num=num+1;
        cout<<num<<"."<<t->title<<endl;
        t=t->next;
    }
}
void read(list *ls)
{
    fstream file;
    file.open("Diary.txt",ios::in);
    string title,day,month,year,des;
    if(!file)
    {
        cout<<"File not Found!"<<endl;
    }else
    {
        while(!file.eof())
        {
            getline(file,title);
            getline(file,day);
            getline(file,month);
            getline(file,year);
            getline(file,des);
            add(ls,title,day,month,year,des);

        }
    }
    file.close();
}
void write(list *ls)
{
    fstream file;
    file.open("Diary.txt",ios::out);
    Element *t;
    t=ls->head;
    while(t->next!=NULL)
    {
        file<<t->title<<endl;
        file<<t->day<<endl;
        file<<t->month<<endl;
        file<<t->year<<endl;
        file<<t->des<<endl;
        t=t->next;
    }
    file<<t->title<<endl;
    file<<t->day<<endl;
    file<<t->month<<endl;
    file<<t->year<<endl;
    file<<t->des;
}
bool search(list *ls,string sear)
{
    Element *d;
    d=ls->head;
    int num=0;
    while(d!=NULL)
    {
        if(d->title==sear)
        {
            num++;
            break;
        }else
        {
            d=d->next;
        }
    }if(num>0)
    {
        cout<<endl;
        cout<<"\t\t\t\t------------------------"<<d->title<<"------------------------"<<endl;
        cout<<d->day<<"-"<<d->month<<"-"<<d->year<<endl;
        cout<<"Dear Diary,"<<endl;
        cout<<endl;
        cout<<"\t"<<d->des<<endl;
        return true;
    }else
    {
        return false;
    }
}
void update(list *ls,string title2)
{
    Element *g;
    g=ls->head;
    while(g!=NULL)
    {
        if(g->title==title2)
        {
           cout<<endl;
           int num;
           cout<<"1.update your title."<<endl;
           cout<<"2.update your date."<<endl;
           cout<<"3.update your description."<<endl;
           cout<<"4.Exit."<<endl;
           cout<<"\t\tChoose your option : ";
           cin>>num;
           if(num==1)
           {
               cout<<endl;
               cout<<"Title : "<<g->title<<endl;
               string title1;
               cout<<"\tEnter the new Title : ";
               cin.ignore();
               getline(cin,title1);
               g->title=title1;
               cout<<"Update Title Successful"<<endl;
           }else if(num==2)
           {
               cout<<endl;
               cout<<"Date : "<<g->day<<"-"<<g->month<<"-"<<g->year<<endl;
               string day1,month1,year1;
               int opt;
               cout<<endl;
               cout<<"1.Update day."<<endl;
               cout<<"2.Update month."<<endl;
               cout<<"3.Update year."<<endl;
               cout<<"4.Exit."<<endl;
               cout<<"\t\tChoose your option : ";
               cin>>opt;
               if(opt==1)
               {
                    cout<<endl;
                    cout<<"\tEnter the new day/00 : ";
                    cin>>day1;
                    g->day=day1;
                    cout<<"Update day Successful"<<endl;
               }else if(opt==2)
               {
                    cout<<endl;
                    cout<<"\tEnter the new month/00 : ";
                    cin>>month1;
                    g->month=month1;
                    cout<<"Update Month Successful"<<endl;
               }else if(opt==3)
               {
                    cout<<endl;
                    cout<<"\tEnter the new year/0000 : ";
                    cin>>year1;
                    g->year=year1;
                    cout<<"Update Year Successful"<<endl;
               }else if(opt==4)
               {
                   break;
               }else
               {
                   cout<<endl;
                   cout<<"Invalid Number!"<<endl;
               }
           }
           else if(num==3)
           {
               cout<<endl;
               cout<<"Description : "<<g->des<<endl;
               string des1;
               cout<<"\tEnter the new Description : ";
               cin.ignore();
               getline(cin,des1);
               g->des=des1;
               cout<<"Update Description Successful"<<endl;
           }else if(num==4)
           {
               break;
           }else
           {
               cout<<endl;
               cout<<"Invalid Number!"<<endl;
           }
        }else
        {
            g=g->next;
        }
    }
}
bool remove(list *ls,string data){
    int p=0,e=0;
    if(ls->n == 0){
        cout << "The list is empty" << endl;
    }else if(ls->head->title == data){
        Element* current;
        current=ls->head;
        ls->head = ls->head->next;
        delete current;
        ls->n=ls->n-1;
    }else{
        Element* previous = ls->head;
        Element* current = ls->head->next;
        while(current != NULL) {
            if(current->title == data) {
                p++;
                break;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
        if(current == NULL) {
            cout << "Can't remove value: no match found.\n";
        } else {
            previous->next = current->next;
        }
        if(p>0)
        {
            return true;
            delete current;
            ls->n=ls->n-1;
        }else if(p==0)
        {
            return false;
        }
    }
}
void finddisplay(list * ls,string day2,string month2,string year2,string day3,string month3,string year3)
{
    Element *k;
    k=ls->head;
    while(k!=NULL)
    {
        if(year3>k->year && year2<k->year)
        {
            cout<<endl;
            cout<<"\t\t\t\t------------------------"<<k->title<<"------------------------"<<endl;
            cout<<k->day<<"-"<<k->month<<"-"<<k->year<<endl;
            cout<<"Dear Diary,"<<endl;
            cout<<endl;
            cout<<"\t"<<k->des<<endl;
        }else if(year3==k->year || year2==k->year)
        {
            if(month3>k->month && month2<k->month)
            {
                cout<<endl;
                cout<<"\t\t\t\t------------------------"<<k->title<<"------------------------"<<endl;
                cout<<k->day<<"-"<<k->month<<"-"<<k->year<<endl;
                cout<<"Dear Diary,"<<endl;
                cout<<endl;
                cout<<"\t"<<k->des<<endl;
            }else if(month3==k->month ||month2==k->month)
            {
                if(day3>k->day && day2<k->day)
                {
                    cout<<endl;
                    cout<<"\t\t\t\t------------------------"<<k->title<<"------------------------"<<endl;
                    cout<<k->day<<"-"<<k->month<<"-"<<k->year<<endl;
                    cout<<"Dear Diary,"<<endl;
                    cout<<endl;
                    cout<<"\t"<<k->des<<endl;
                }else if(day3==k->day || day2==k->day)
                {
                    cout<<endl;
                    cout<<"\t\t\t\t------------------------"<<k->title<<"------------------------"<<endl;
                    cout<<k->day<<"-"<<k->month<<"-"<<k->year<<endl;
                    cout<<"Dear Diary,"<<endl;
                    cout<<endl;
                    cout<<"\t"<<k->des<<endl;
                }
            }
        }
        k=k->next;
    }
}
int main()
{
    list *ls;
    ls=new list;
    ls->n=0;
    read(ls);
    cout<<"\t\t\t\t============================================================"<<endl;
    cout<<"\t\t\t\t--------------Welcome to Diary Note Management--------------"<<endl;
    cout<<"\t\t\t\t============================================================"<<endl;
    while (true)
    {
        cout<<endl;
        cout<<"1.Create your diary note."<<endl;
        cout<<"2.Show all diary note."<<endl;
        cout<<"3.Show detail of a specific diary note."<<endl;
        cout<<"4.Update your diary note."<<endl;
        cout<<"5.Show all diary from a created date to another created date."<<endl;
        cout<<"6.Delete your diary note."<<endl;
        cout<<"7.Exit Program."<<endl;
        string opt;
        cout<<endl;
        cout<<"\t\tChoose option : ";
        cin>>opt;
        if(opt=="1")
        {
            cout<<endl;
            string title,day,month,year,des,check;
            cout<<"\tEnter your Title : ";
            cin.ignore();
            getline(cin,title);
            cout<<"\tEnter day/00 : ";
            getline(cin,day);
            cout<<"\tEnter month/00 : ";
            getline(cin,month);
            cout<<"\tEnter year/0000 : ";
            getline(cin,year);
            cout<<"\tEnter your description : ";
            getline(cin,des);
            cout<<"Are you sure you want to add this diary note? yes/no : ";
            cin>>check;
            if(check=="yes")
            {
                cout<<endl;
                add(ls,title,day,month,year,des);
                cout<<"Add Successful!"<<endl;
            }else if(check=="no")
            {
                cout<<"";
            }else
            {
                cout<<endl;
                cout<<"please choose only yes or no!!"<<endl;
            }
        }else if(opt=="2")
        {
            cout<<endl;
            display(ls);
        }else if(opt=="3")
        {
            cout<<endl;
            string sear;
            cout<<"\tEnter your Title of diary note you want to see : ";
            cin.ignore();
            getline(cin,sear);
            if(search(ls,sear))
            {
                cout<<"";
            }else
            {
                cout<<endl;
                cout<<"Diary note not Found!"<<endl;
            }
        }else if(opt=="4")
        {
            cout<<endl;
            string title2;
            cout<<"\tEnter your Title of diary note you want to update : ";
            cin.ignore();
            getline(cin,title2);
            update(ls,title2);
        }else if(opt=="5")
        {
            cout<<endl;
            string day2,month2,year2,day3,month3,year3;
            cout<<"Enter day/month/year to day/month/year to show all diary not."<<endl;
            cout<<"\tEnter From what day."<<endl;
            cout<<"\t\tEnter day : ";
            cin>>day2;
            cout<<"\t\tEnter month : ";
            cin>>month2;
            cout<<"\t\tEnter year : ";
            cin>>year2;
            cout<<"\tEnter to Another day."<<endl;
            cout<<"\t\tEnter day : ";
            cin>>day3;
            cout<<"\t\tEnter month : ";
            cin>>month3;
            cout<<"\t\tEnter year : ";
            cin>>year3;
            finddisplay(ls,day2,month2,year2,day3,month3,year3);
        }else if(opt=="6")
        {
            cout<<endl;
            string title3;
            cout<<"\tEnter your Title of diary note you want to delete : ";
            cin.ignore();
            getline(cin,title3);
            string ask;
            cout<<"Are you sure you want to delete this Diary note?  yes/no : ";
            cin>>ask;
            if(ask=="yes")
            {
                if(remove(ls,title3))
                {
                    cout<<endl;
                    cout<<"Delete Successful!"<<endl;
                }else
                {
                    cout<<endl;
                    cout<<"Delete Not Successful!"<<endl;
                }
            }else if(ask=="no")
            {
                cout<<"";
            }else
            {
                cout<<endl;
                cout<<"Please choose yes or no only!!"<<endl;
            }
        }
        else if(opt=="7")
        {
            cout<<endl;
            cout<<"Thank your for using our Program."<<endl;
            write(ls);
            break;
        }else
        {
            cout<<"Invalid Number"<<endl;
        }
    }
    return 0;
}
