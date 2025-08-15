#include<iostream>
#include<conio.h>

using namespace std;

const int SIZE = 5;

string username[SIZE];
string password[SIZE];

int count_user = 0;

string getPassword() 
{
    string pass = "";
    char ch;
    
    while (true) 
    {
        ch = _getch(); 
        // take input without showing
        if (ch == 13)
        {
            break; // Enter key
        } 
        else if (ch == 8) // Backspace key 
        {     
            if (!pass.empty()) 
            {
                cout << "\b \b"; // erase star from screen
                pass.pop_back(); // remove last char from string
            }
        }
        else {
            pass += ch;
            cout << '*'; // show star
        }
    }
    cout << endl;
    return pass;
}

void Register()
{
    if(count_user < SIZE)
    {
        cout<<"\nRegister a new user";
        cout<<"\nEnter the Username : ";
        cin>>username[count_user];
        cout<<"\nEnter the Password(Masking Enabled) : ";
        password[count_user] = getPassword();
        count_user++;

        cout<<"\nRegistration Successfully!!"<<endl;
    }
}

void login()
{
    string pusername;
    string upassword;
    int found = 0;

    cout<<"\nEnter the Username : ";
    cin>>pusername;
    cout<<"\nEnter the Password(Masking Enabled) : ";
    upassword = getPassword();
    
        for(int i = 0;i<count_user;i++)
        {
            if(password[i] == upassword && username[i] == pusername)
            {
                cout<<"\nLogin Successfully!! Welcome, "<<username[i]<<"!"<<endl;
                found = 1;
                break;
            }
        }
        if(!found)
        {
            cout<<"\nLogin Falied! Incorrect Username or Password."<<endl;
        }
}

void show_menu()
{
    cout<<"\n1. Register";
    cout<<"\n2. Login";
    cout<<"\n3. Exit";
}

int main()
{
    int choice;

    cout<<"\n----------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n                                                        USER MANAGEMENT SYSTEM";
    cout<<"\n----------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n                                                                                                            Created By [Chirag Shrimali]"<<endl;
    
    while(1)
    {
        show_menu();

        cout<<"\nSelect an Option : ";
        cin>>choice;

        if(choice > 0 && choice < 4)
        {
            switch(choice)
            {
                case 1 : Register();
                         break;

                case 2 : login();
                         break;

                case 3 : cout<<"\nExiting Successfully!!"<<endl;
                         exit(0);
            }
        }
    }
    
    return 0;
}