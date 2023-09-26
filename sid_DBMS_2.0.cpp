#include<iostream>
using namespace std;
class staff
{
public:
    int sid;
    char name[100];
    staff()
    {
        cout<<"\n Enter your Staff ID :";
        cin>>sid;
        cout<<"\n Enter Employee Name :";
        cin>>name;
        cout<<"\n Staff ID is :"<<sid;
        cout<<"\n Employee Name is:"<<name;
    }
};
class accountant : virtual public staff
{
public:
    int asalary,gsal,nsal,ta,da,pf;

    accountant()
    {
        cout<<"\n Enter Accountant Salary :";
        cin>>asalary;

        ta=(asalary/100)*7;
        da=(asalary/100)*2;
        pf=(asalary/100)*12.5;
        gsal=asalary+ta+da;
        nsal=gsal-pf;

        cout<<"\n Staff ID is :"<<sid;
        cout<<"\n Accountant Name :"<<name;
        cout<<"\n Accountant Net Salary is :"<<nsal;

    }
};
class faculty : virtual public staff
{
public:
    faculty()
    {

    }
};
class perma_faculty : public faculty
{
public:
    int psal;

    perma_faculty()
    {
        cout<<"\n Enter Permanent Salary :";
        cin>>psal;
        cout<<"\n Faculty Permanent Salary is :"<<psal;
    }
};
class visi_faculty : public faculty
{
public:
    int vsal,lecture;

    visi_faculty()
    {
        cout<<"\n Enter number of lectures taken :";
        cin>>lecture;
        vsal=lecture*800;
        cout<<"\n Faculty Visiting Salary is :"<<vsal;
    }
};
class labour : virtual public staff
{
public:
    int lsal,days;

    labour()
    {
        cout<<"\n Enter number of days worked :";
        cin>>days;
        cout<<"\n Labour Name is :"<<name;
        cout<<"\n Staff ID is :"<<sid;
        lsal=days*300;
        cout<<"\n Labour Salary is :"<<lsal;
    }
};
int main()
{
    int n;
    cout<<"Staff Database System 2.0"<<endl;
    cout<<"\n 1. Accountant Details"<<"\n 2. Permanent Faculty Details"<<"\n 3. Visiting Faculty Details"<<"\n 4. Labour Details"<<endl;
    cout<<"\n Enter your choice :"<<endl;
    cin>>n;

    switch(n)
    {

    case 1:
        {
             accountant a;
             break;
        }


    case 2:
        {
            perma_faculty pf;
            break;
        }

    case 3:
       {
           visi_faculty vf;
           break;
       }

    case 4:
        {
            labour l;
            break;
        }

    default:
        cout<<"\n You've Entered a wrong option. Please try again . . .";
        break;
    }


}
