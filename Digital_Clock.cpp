#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<windows.h>

using namespace std;

int main()
{
    time_t current_time;
    struct tm *time_d;
    char buffer[100];
    char date[100];
    int choice;
    int clockRow = 19;

    cout<<"\nChoose the Time Format : "<<endl;
    cout<<"-----------------------------";
    cout<<"\n1. 24 Hour Format";
    cout<<"\n2. 12 Hour Format (default)"<<endl;
    cout<<"-----------------------------";

    cout<<"\nEnter Your Choice (1/2) : ";
    cin>>choice;

    cout<<"\n";

    while(1)
    {
        time(&current_time);
        time_d = localtime(&current_time);
        if(choice == 1)
        {
            strftime(buffer , sizeof(buffer) , "%H:%M:%S" , time_d);
            strftime(date , sizeof(date) , "%A %B %d %Y" , time_d);
        }
        else if(choice == 2)
        {
            strftime(buffer , sizeof(buffer) , "%I:%M:%S %p" , time_d);
            strftime(date , sizeof(date) , "%A %B %d %Y" , time_d);
        }
        else{
            cout<<"\nInvalid choice selection for time format please select the valid choice.";
        }
            cout << "\033[" << clockRow << ";1H";
            cout<<"\nThe Current Time is : "<<buffer<<flush<<endl;
            cout<<"\nThe Date is : "<<date<<endl;

            Sleep(1000); // sleep the device system for the 1 sec
    }    

    return 0;
}