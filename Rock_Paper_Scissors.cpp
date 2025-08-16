#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    string player;
    string opponent;
    int playerscore = 0;
    int opponentscore = 0;
    srand(time(NULL));
    string rps[] = {"Rock" , "Paper" , "Scissors"};

    cout<<"\n    |                              |";
    cout<<"\n----|------------------------------|----";
    cout<<"\n    | Rock | Paper | Scissors Game |";
    cout<<"\n----|------------------------------|----";
    cout<<"\n    |                              |";

    while(true)
    {
        opponent = rps[rand() % 3]; // generating random 3 choice rock , paper , scissors

        cout<<"\nEnter the Player Choice (Rock/Paper/Scissors) : ";
        cin>>player;
        // getline(cin , player);
        cout<<"\nThe Opponent Choose is : "<<opponent<<endl;

        if(player != "Rock" && player != "Paper" && player != "Scissors")
        {
            break;
        }
        else if(player == opponent)
        {
            opponentscore++;
            playerscore++;
        }
        else if(player == "Rock")
        {
            if(opponent == "Paper")
            {
                opponentscore++;
            }
            else if(opponent == "Scissors")
            {
                playerscore++;
            }
        }
        else if(player == "Paper")
        {
            if(opponent == "Rock")
            {
                playerscore++;
            }
            else if(opponent == "Scissors")
            {
                opponentscore++;
            }
        }
        else if(player == "Scissors")
        {
            if(opponent == "Paper")
            {
                playerscore++;
            }
            else if(opponent == "Rock")
            {
                opponentscore++;
            }
        }
            cout<<"\nPlayerScore : "<<playerscore<<endl;
            cout<<"\nOpponentScore : "<<opponentscore<<endl;
    }

        cout<<"\nPlayerScore : "<<playerscore<<endl;
        cout<<"\nOpponentScore : "<<opponentscore<<endl;

        if(playerscore > opponentscore)
        {
            cout<<"\nPlayer Wins!!";
        }
        else if(opponentscore > playerscore)
        {
            cout<<"\nOpponent Wins!!";
        }
        else{
            cout<<"\nTie!";
        }
    
    return 0;
}