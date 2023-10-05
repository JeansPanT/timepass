#include<iostream>
#include<string.h>
using namespace std;
class bank
{
public:
    char bname[100],ifsc[100];
    void get()
    {

    }
};
class customer : public bank
{
public:
    char name[100],add[100];
    void get()
    {
        cout<<"\n Enter your name      :"<<endl;
        cin>>name;
        cout<<"\n Enter your address   :"<<endl;
        cin>>add;
        cout<<"\n Enter your bank name :"<<endl;
        cin>>bname;
        cout<<"\n Enter your IFSC Code :"<<endl;
        cin>>ifsc;
    }
};
class normal : virtual public customer
{
public:
    char accno[100],acctype[100];
    void get1()
    {
        cout<<"\n Enter your account no. :"<<endl;
        cin>>accno;
        cout<<"\n Enter your account type [ Saving / Current ]  : "<<endl;
        cin>>acctype;
    }
    void show()
    {
        cout<<"\n Bank Management System by Sid 2.0"<<endl;
        cout<<"\n Customer Name : "<<name;
        cout<<"\n Bank Name     : "<<bname;
        cout<<"\n Address       : "<<add;
        cout<<"\n IFSC Code     : "<<ifsc;
        cout<<"\n Account No.   : "<<accno;
        cout<<"\n Account Type. : "<<acctype;
    }
};
class business : virtual public customer
{
public:
    char ano[100],atype[100];
    void get2()
    {
        cout<<"\n Enter your account no. :"<<endl;
        cin>>ano;
        cout<<"\n Enter your account type [ Saving / Current / Overseas ]  : "<<endl;
        cin>>atype;
    }
    void show()
    {
        cout<<"\n Bank Management System by Sid 2.0"<<endl;
        cout<<"\n Customer Name : "<<name;
        cout<<"\n Bank Name     : "<<bname;
        cout<<"\n Address       : "<<add;
        cout<<"\n IFSC Code     : "<<ifsc;
        cout<<"\n Account No.   : "<<ano;
        cout<<"\n Account Type. : "<<atype;
    }
};
class bank_act : public bank
{
public:
    int p,r,t,si;
    char loan[100];
    void get()
    {
        cout<<"\n Enter the type of Loan [ Personal / House / AL ] :";
        cin>>loan;
        cout<<"\n Enter Principle Amount :";
        cin>>p;
        cout<<"\n Enter Rate of Interest :";
        cin>>r;
        cout<<"\n Enter loan duration    :";
        cin>>t;
    }
    void show()
    {
        si=(p*r*t)/100;
        cout<<"\n Loan type             :"<<loan;
        cout<<"\n Loan Amount           :"<<p;
        cout<<"\n Loan Rate of Interest :"<<r<<"%";
        cout<<"\n Loan duration         :"<<t<<"Years";
        cout<<"\n Loan Interest Amount  :"<<si;
    }
};
int main()
{

    int no,num;
    normal n;
    business b;
    bank_act ba;
    string userName;
    string userPassword;
    int loginAttempt = 0;
    while (loginAttempt <= 3)
    {
        cout<<"\n Bank Management System by Sid 2.0"<<endl;
        cout << "\n Please enter your user name: ";
        cin >> userName;
        cout << "\n Please enter your user password: ";
        cin >> userPassword;

        if (userName == "sid" && userPassword == "sid@123")
        {
            cout << "Welcome Siddharth!\n"<<endl;
            cout<<"\n Bank Management System by Sid 2.0"<<endl;
            cout<<"\n 1. Update Customer Details -"<<"\n 2. Check Bank Activities -"<<"\n 3. Exit -"<<endl;
            cout<<"\n Enter your choice :";
            break;
        }
        else if (userName == "yash" && userPassword == "yash@123")
        {
            cout << "Welcome Yashwardhan!\n"<<endl;
            cout<<"\n Bank Management System by Sid 2.0"<<endl;
            cout<<"\n 1. Update Customer Details -"<<"\n 2. Check Bank Activities -"<<"\n 3. Exit -"<<endl;
            cout<<"\n Enter your choice :";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
        if (loginAttempt == 3)
            {
                cout << "Too many login attempts! The program will now terminate.";
                cout << "Thank you for logging in.\n";
                }
    }
    cin>>no;

    switch(no)
    {
    case 1:
        {
            cout<<"\n 8. Normal Customer -"<<"\n 9. Businessman -";
            cout<<"\n Enter your choice :";
            cin>>num;

            switch(num)
            {
            case 8:
                {
                    n.customer::get();
                    n.normal::get1();
                    n.normal::show();
                    break;
                }

            case 9:
                {
                    b.customer::get();
                    b.business::get2();
                    b.business::show();
                    break;
                }
                break;
            }
            break;
        }
    case 2:
        {
            ba.bank_act::get();
            ba.bank_act::show();
            break;
        }
    case 3:
        {
            cout<<"\n You've successfully exited . . .";
            break;
        }
    default:
        {
            cout<<"Invalid choice";
            break;
        }
    }
}
