#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Student
{
    char* id;
    float gpa=0;
public:
    char* name;
    int level;
    Student(char[], char[], int);
    void set_all(char[], char[], int, float);
    void set_name(char[]);
    void set_id(char[]);
    void set_level(int);
    void set_gpa(float);
    char* get_name();
    char* get_id();
    int get_level();
    float get_gpa();
    void stdcopy(Student &);
    bool before(Student &a);
    bool greatThan(Student &a);
    void update(Student &a);
    ~Student();
};

Student::Student(char _name[] = "", char _id[] = "", int _level = 1)
{
    set_all(_name, _id, _level, 0);
}

void Student::set_all(char _name[], char _id[], int _level, float _gpa)
{
    set_name(_name);
    set_id(_id);
    set_level(_level);
    set_gpa(_gpa);
}
void Student::set_name(char _name[])
{
    name = new char[strlen(_name)+1];
    strcpy(name,_name);
}
void Student::set_id(char _id[])
{
    id = new char[strlen(_id)+1];
    strcpy(id,_id);
}
void Student::set_level(int _level)
{
    if(_level>0 && _level <= 8)
        level = _level;
    else
        level = 1;
}
void Student::set_gpa(float _gpa)
{
    if(_gpa>0 && _gpa<=4)
        gpa = _gpa;
    else
        gpa = 0;
}
char* Student::get_name()
{
    return name;
}
char* Student::get_id()
{
    return id;
}
int Student::get_level()
{
    return level;
}
float Student::get_gpa()
{
    return gpa;
}

void Student::stdcopy(Student &s)
{
    name = new char[strlen(s.get_name())+1];
    strcpy(name,s.get_name());
    id = new char[strlen(s.get_id())+1];
    strcpy(id,s.get_id());
    level = s.get_level();
    gpa = s.get_gpa();
}

bool Student::greatThan(Student &a)
{
    if(level<=a.level)
        return 1;
    else return 0;
}
bool Student::before(Student &a)
{
    if(strcmp(name,a.name)<=0)
        return true;
    else return false;
}

Student::~Student()
{
    delete []name;
    delete []id;
}
void sort_name(Student[], int);
void sort_level(Student[], int);
int main()
{
    Student s[3] =
    {
        Student ("a","15b1seas1111",2),
        Student ("c","14b1seas2222",3),
        Student ("b","15b1seas3333",2),
    };

    char choose[20];
    while(true)
    {
        cin>>choose;
        if(strcmp(choose,"sortname")==0)
        {
            sort_name(s,3);
            for(int i=0; i<3; i++)
            {
                cout<< s[i].get_name() << "|" << s[i].get_id() << "|" << s[i].get_level() << "|" << s[i].get_gpa() << endl;
            }
        }
        if(strcmp(choose,"sortlevel")==0)
        {
            sort_level(s,3);
            for(int i=0; i<3; i++)
            {
                cout <<s[i].get_name() << "|" << s[i].get_id() << "|" << s[i].get_level() << "|" << s[i].get_gpa() << endl;
            }
        }
    }
}


void Student::update(Student &a)
{
    char change[20];
    strcpy(change,name);
    strcpy(name,a.name);
    strcpy(a.name,change);
    int changee;
    changee=level;
    level=a.level;
    a.level=changee;
    char z[20];
    strcpy(z,id);
    strcpy(id,a.id);
    strcpy(a.id,z);
    int k;
    k=gpa;
    gpa=a.gpa;
    a.gpa=k;
}
void sort_name(Student a[],int n)
{
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n-1; i++)
        {
            if(a[i].before(a[i+1])==0)
            {
                a[i].update(a[i+1]);
            }
        }
    }
}

void sort_level(Student a[],int n)
{
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n-1; i++)
        {
            if(a[i].greatThan(a[i+1])==1)
            {
                a[i].update(a[i+1]);
            }
        }
    }
}

