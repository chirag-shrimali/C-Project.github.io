#include<iostream>

using namespace std;

const int task = 100;

string task_name[task];
int count_task = 0;

void add_task()
{
    if(count_task < task)
    {
        cout<<"\nEnter the Task : ";
        cin>>task_name[count_task];
        cout<<"\nTasks Added Successfully!!"<<endl;
        count_task++;
    }
}

void remove_task()
{
    string task;
    int i,j;

    cout<<"\nEnter the tasks that you want to be remove : ";
    cin>>task;

    for(i = 0;i<count_task;i++)
    {
        if(task == task_name[i])
        {
            break;
        }
    }

    for(j = i;j<count_task - 1;j++)
    {
        task_name[j] = task_name[j + 1];
    }
        cout<<"\nTasks Removed Successfully!!"<<endl;
        count_task--;
}

void show_task()
{

    for(int i = 0;i<count_task;i++)
    {
        cout<<"\n- "<<task_name[i]<<endl;
    }
}

void show_list()
{
    cout<<"\n1. Add Tasks";
    cout<<"\n2. Remove Tasks";
    cout<<"\n3. Shows Tasks";
    cout<<"\n4. Exit";
}

int main()
{
    int choice;
    cout<<"\n**********************************";
    cout<<"\n|         Welcome to the         |";
    cout<<"\n|           TO DO LIST           |";
    cout<<"\n**********************************";

    while(true)
    {
        show_list();

        cout<<"\nEnter Your Choice (1-4) : ";
        cin>>choice;

        if(choice > 0 && choice < 5)
        {
            switch(choice)
            {
                case 1 : add_task();
                         break;

                case 2 : remove_task();
                         break;

                case 3 : show_task();
                         break;

                case 4 : cout<<"\nExiting Successfully!!";
                         exit(0);
            }
        }
        else{
            cout<<"\nInvalid Choice of Selection Please Select the valid Choice."<<endl;
        }
    }
    

    return 0;
}