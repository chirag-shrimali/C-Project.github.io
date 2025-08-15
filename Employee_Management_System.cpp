#include<iostream>

using namespace std;

const int SIZE = 100;

int emp_id[SIZE];
string emp_name[SIZE];
int emp_salary[SIZE];
int count_emp = 0;

// Add_Employee
void add_emp()
{
    if(count_emp < SIZE)
    {
        cout<<"\nEnter the Employee's ID : ";
        cin>>emp_id[count_emp];
        cout<<"\nEnter the Employee's Name : ";
        // cin>>emp_name[count_emp];
        cin.ignore();
        getline(cin, emp_name[count_emp]);
        cout<<"\nEnter the Employee's Salary : ";
        cin>>emp_salary[count_emp];
        count_emp++;
        cout<<"\nEmployee Added Successfully!!!"<<endl;
    }
    else{
        cout<<"\nThe Array becomes Full."<<endl;
    }
}

// Updating Employees

void update_emp()
{
    int id;
    int found = 0;

    cout<<"\nEnter the Employee's ID that you want to be Update : ";
    cin>>id;

    for(int i = 0;i<count_emp;i++)
    {
        if(emp_id[i] == id)
        {
            // cout<<"\nEnter the Updated Employee's Name : ";
            // cin>>emp_name[i];
            cout<<"\nEnter the Updated Employee's Name : ";
            cin.ignore();
            getline(cin, emp_name[i]);

            cout<<"\nEnter the Updated Employee's Salary : ";
            cin>>emp_salary[i];
            found = 1;
            cout<<"\nEmployee Updated Successfully!!!"<<endl;
            break;
        }
    }
    if(!found)
    {
        cout << "\nNo employee found with the entered ID. Please check and try again."<<endl;
    }
}

// Deleting Employees

void del_emp()
{
    int id;
    int i,j;

    cout<<"\nEnter the Employee's ID that you want to be delete : ";
    cin>>id;

    for(i = 0;i<count_emp;i++)
    {
        if(emp_id[i] == id)
        {
            break;
        }
    }

    for(j = i;j<count_emp - 1;j++)
    {
        emp_id[j] = emp_id[j+1];
        emp_name[j] = emp_name[j+1];
        emp_salary[j] = emp_salary[j+1];
    }
        count_emp--;
    cout<<"\nEmployee Deleted Successfully!!!"<<endl;
}

// Displaying Employees

void disp_emp()
{
    cout<<"\n"<<"ID"<<"\tName"<<"\t\tSalary"<<endl;
    for(int i = 0;i<count_emp;i++)
    {
        cout<<emp_id[i]<<"\t"<<emp_name[i]<<"\t"<<emp_salary[i]<<"\t"<<endl;
    }        
}

// Search Employees

void search_emp()
{
    int id;
    int found = 0;

    cout<<"\nEnter the Employee's ID that you want to be search : ";
    cin>>id;

    for(int i = 0;i<count_emp;i++)
    {
        if(id == emp_id[i])
        {
            cout<<"\nID : "<<emp_id[i];
            cout<<"\nName : "<<emp_name[i];
            cout<<"\nSalary : "<<emp_salary[i]<<endl;
            found = 1;
            break;
        }
    }
    if(!found)
    {
        cout<<"\nNo employee found with the entered ID. Please check and try again."<<endl;
    }
}

// showing the choices

void show_menu()
{
        cout<<"\n1.Add Employee.";
        cout<<"\n2.Update Employee.";
        cout<<"\n3.Delete Employee.";
        cout<<"\n4.Display Employee.";
        cout<<"\n5.Search Employee.";
        cout<<"\n6.Exit";
}

// main function

int main()
{
    int choice;
    
    cout << "\n===========================================================================================================================";
    cout << "\n\t\t\t\t\t     EMPLOYEE MANAGEMENT SYSTEM"<<endl;
    cout << "===========================================================================================================================\n";
    cout<<"                                                                                               Created by [Chirag Shrimali]"<<endl;
    
    show_menu();
    
    while(true)
    {
        cout<<"\nEnter Your Choice (1-6) : ";
        cin>>choice;
    
        if(choice > 0 && choice < 7)
        {
            switch(choice)
                {
                        case 1 : add_emp();
                                 break;
    
                        case 2 : update_emp();
                                 break;
    
                        case 3 : del_emp();
                                 break;
    
                        case 4 : disp_emp();
                                 break;

                        case 5 : search_emp();
                                 break;
                             
                                 case 6 :   cout<<"\nExit Successfully!!!";
                                            exit(0);
                    }
        }
        else{
            cout << "\nOops! That's not a valid option. Kindly select a valid employee's choice."<<endl;  
        }
                
                show_menu();
    }
        return 0;
}