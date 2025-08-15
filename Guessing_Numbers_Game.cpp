#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    int random , guess;
    int no_of_guess = 0;
    srand(time(NULL));

    cout<<"============================================================================================================================";
    cout<<"\n\t\t\t\t         Welcome to the World Guessing Numbers Game"<<endl;
    cout<<"============================================================================================================================";
    cout<<"\n                                                                                              Created By [Chirag Shrimali]";
    random = rand() % 100 + 1; // generating the numbers between 1 to 100

    do{
        cout<<"\n\nEnter Your Guessing Number Between (1 - 100) : ";
        cin>>guess;
        no_of_guess++;

        if(guess < random)
        {
            cout<<"\nGuess a larger Numbers.";
        }
        else if(guess > random)
        {
            cout<<"\nGuess a Smaller Number.";
        }
        else{
            cout<<"\nCongratulations!!! You are Guessing the Correct Numbers With the "<<no_of_guess<<" attempts.";
        }
    }while(guess != random);

    cout<<"\nThanks For Playing World Guessing Numbers Game.";

    cout<<"\nEmail Address is [chiragshrimali2147@gmail.com]";

    return 0;
}