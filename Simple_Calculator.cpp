#include<iostream>
#include<math.h>

using namespace std;

float no1;
float no2;
float ans;

void addition()
{
    cout<<"\nEnter the No1 : ";
    cin>>no1;
    cout<<"\nEnter the No2 : ";
    cin>>no2;

    ans = no1 + no2;

    cout<<"\nAddition is : "<<ans<<endl;
}

void subtract()
{
    cout<<"\nEnter the No1 : ";
    cin>>no1;
    cout<<"\nEnter the No2 : ";
    cin>>no2;

    ans = no1 - no2;

    cout<<"\nSubtraction is : "<<ans<<endl;
}

void multiply()
{
    cout<<"\nEnter the No1 : ";
    cin>>no1;
    cout<<"\nEnter the No2 : ";
    cin>>no2;

    if(no1 == 0 || no2 == 0)
    {
        cout<<"\nInvalid Argument for Multiplication."<<endl;
    }
    else{
        ans = no1 * no2;

        cout<<"\nMultiplication is : "<<ans<<endl;
    }
}

void division()
{
    cout<<"\nEnter the No1 : ";
    cin>>no1;
    cout<<"\nEnter the No2 : ";
    cin>>no2;

    if(no2 == 0)
    {
        cout<<"\nInvalid Argument for Division."<<endl;
    }
    else{
        ans = no1 / no2;

        cout<<"\nDivision is : "<<ans<<endl;
    }
}

void remainder()
{
    int a,b;
    int mod;

    cout<<"\nEnter the No1 : ";
    cin>>a;
    cout<<"\nEnter the No2 : ";
    cin>>b;

    mod = a % b;

    cout<<"\nModulus is : "<<mod<<endl;
}

void power()
{
    cout<<"\nEnter the No1 : ";
    cin>>no1;
    cout<<"\nEnter the No2 : ";
    cin>>no2;

    ans = pow(no1,no2);

    cout<<"\nPower is : "<<ans<<endl;
}

void showlist()
{
    cout<<"\n1.Addition";
    cout<<"\n2.Subtraction";
    cout<<"\n3.Multiplication";
    cout<<"\n4.Division";
    cout<<"\n5.Modulus";
    cout<<"\n6.Power";
    cout<<"\n7.Exit";
}

int main()
{
    int choice;

    cout<<"============================================================================================================================";
    cout<<"\n\t\t\t\t                    Welcome to the Simple Calculator"<<endl;
    cout<<"============================================================================================================================";
    cout<<"\n                                                                                                Created By [Chirag Shrimali]";
    while(1)
    {
        showlist();

        cout<<"\nEnter Your Choice Between (1 - 7) : ";
        cin>>choice;

        if(choice > 0 && choice < 8)
        {
            switch(choice)
            {
                case 1 : addition();
                         break;

                case 2 : subtract();
                         break;

                case 3 : multiply();
                         break;

                case 4 : division();
                         break;

                case 5 : remainder();
                         break;

                case 6 : power();
                         break;

                case 7 : cout<<"\nExiting Successfully!!!";
                         exit(0);
            }
        } 
        else{
            cout<<"\nOops!! You are select an invalid choice please select valid choice."<<endl;
        }
    }
    return 0;
}