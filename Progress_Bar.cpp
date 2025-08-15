#include<iostream>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

const int progress_bar_length = 100;
const int MAX_progress_bar = 5;

struct Task
{
    int id;
    int progress;
    int step;
};


void input_progress_bar(Task tasks)
{
    int show_progress = (tasks.progress * progress_bar_length) / 100;

    cout<<"\nTask "<<tasks.id<<" : [";

    for(int i = 0;i<progress_bar_length;i++)
    {
        if(i < show_progress)
        {
            cout<<"=";
        }
        else{
            cout<<" ";
        }
    }

    cout<<"] "<<tasks.progress<<"%";
}

int main()
{
    Task task[MAX_progress_bar];
    srand(time(NULL));

    cout<<"\n----------------------------------------------------------";
    cout<<"\n         Welcome to the PROGRESS BAR";
    cout<<"\n----------------------------------------------------------";
    cout<<"\n                              Created By [Chirag Shrimali]"<<endl;


    for(int i = 0;i<MAX_progress_bar;i++)
    {
        task[i].id = i + 1;
        task[i].progress = 0;
        task[i].step = rand() % 15;
    }

    boolean incomplete_tasks = true;

    while(incomplete_tasks)
    {
        incomplete_tasks = false;
        system("cls");
        for(int i = 0;i<MAX_progress_bar;i++)
        {
            task[i].progress += task[i].step; // task[i].progress = task[i].progress + task.step[i];

            if(task[i].progress > 100)
            {
                task[i].progress = 100;
            }
            else if(task[i].progress < 100)
            {
                incomplete_tasks = true;
            }
                input_progress_bar(task[i]);
        }
            Sleep(1000); // Sleep for 1000 seconds
    }

    cout<<"\nAll Tasks are Completed.";

    return 0;
}