#include<iostream>
using namespace std;
class student
{
public:
    char name[100];
    int rno;
    student()
    {
        cout<<"Enter your Name :"<<endl;
        cin>>name;
        cout<<"Enter your Roll Number :"<<endl;
        cin>>rno;
    }
};
class study : virtual public student
{
public:
    int eng,hin,maths,sci,ss,total;
    float per;
    study()
    {
         cout<<"Enter the Marks of English :"<<endl;
         cin>>eng;
         cout<<"Enter the Marks of Hindi"<<endl;
         cin>>hin;
         cout<<"Enter the Marks of Maths"<<endl;
         cin>>maths;
         cout<<"Enter the Marks of Science"<<endl;
         cin>>sci;
         cout<<"Enter the Marks of Social Science"<<endl;
         cin>>ss;

         total=eng+hin+maths+sci+ss;
         per=(total*100)/500;
    }
};
class sports : virtual public student
{
public:
    int score;
    char game[100];
    sports()
    {
        cout<<"Enter your Sports :            [ Chess / Table Tennis ]"<<endl;
        cin>>game;
        cout<<"Enter your score out of 100 :"<<endl;
        cin>>score;
    }
};
class result : public study , public sports
{
public:
    void stu()
    {
        cout<<"\n Marksheet -"<<endl;
        cout<<"\n Student Name :"<<name;
        cout<<"\n Roll Number :"<<rno;
        cout<<"\n Marks of English :"<<eng<<"\n Marks of Hindi :"<<hin<<"\n Marks of Maths :"<<maths<<"\n Marks of Science :"<<sci<<"\n Marks of Social Science :"<<ss<<endl;
        cout<<"\n Total Marks is :"<<total<<" / 500"<<endl;
        cout<<"Percentage is :"<<per<<endl;
    }
    void spo()
    {
        cout<<"\n Sports Performance -"<<endl;
        if(score>=60)
        {
            cout<<"\n You've Qualified for the next Round. . ."<<endl;
            cout<<"Your Score is :"<<score;
        }
        else
        {
            cout<<"\n You've failed to qualify for the next Round. . ."<<endl;
            cout<<"Your Score is :"<<score;
        }
    }

};
int main()
{
    int n;
    cout<<"Student Database Management System 1.0"<<endl;
    result r;
    r.result::stu();
    r.result::spo();
}
