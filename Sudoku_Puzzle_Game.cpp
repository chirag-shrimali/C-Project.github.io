#include<iostream>

using namespace std;

int puzzle[9][9] = {
    {3 , 0 , 0 , 0 , 2 , 0 , 0 , 7 , 0} ,
    {9 , 0 , 0 , 5 , 0 , 0 , 0 , 1 , 4} ,
    {0 , 1 , 6 , 3 , 7 , 0 , 0 , 0 , 8} ,
    {2 , 0 , 0 , 8 , 0 , 0 , 0 , 0 , 1} ,
    {5 , 0 , 0 , 0 , 4 , 1 , 8 , 0 , 0} ,
    {0 , 8 , 9 , 0 , 0 , 0 , 0 , 5 , 0} ,
    {0 , 0 , 5 , 0 , 1 , 0 , 2 , 8 , 0} ,
    {0 , 4 , 0 , 0 , 0 , 6 , 0 , 9 , 3} ,
    {7 , 3 , 1 , 0 , 8 , 2 , 0 , 0 , 0} ,
};

void print_puzzle(int puzzle[9][9]);

int valid_move(int puzzle[9][9] , int row , int col , int val);

int solve_puzzle(int puzzle[9][9] , int row , int col);

int main()
{
    cout<<"\n---|------------------|---";
    cout<<"\n   |SUDOKU PUZZLE GAME|";
    cout<<"\n---|------------------|---"<<endl;

    print_puzzle(puzzle);

    if(solve_puzzle(puzzle , 0 , 0))
    {
        cout<<"\nThe SUDOKU Puzzle is solved.";
        print_puzzle(puzzle);
    }
    else{
        cout<<"\nThis Puzzle is not Solvable.";
    }

    return 0;
}

void print_puzzle(int puzzle[9][9])
{
    cout<<"\n+-------+-------+-------+";

    for(int row = 0;row < 9;row++)
    {
        if(row % 3 == 0 && row != 0)
        {
            cout<<"\n|-------+-------+-------|";
        }
            cout<<"\n";
        for(int col = 0;col < 9;col++)
        {
            if(col % 3 == 0)
            {
                cout<<"| ";
            }
                if(puzzle[row][col] != 0)
                {
                    cout<<puzzle[row][col]<<" ";
                }
                else{
                    cout<<"  ";
                }
        }
                cout<<"|";
    }

    cout<<"\n+-------+-------+-------+";
}

int valid_move(int puzzle[9][9] , int row , int col , int val)
{

    // row validation

    for(int i = 0;i < 9;i++)
    {
        if(puzzle[row][i] == val)
        {
            return 0;
        }
    }

    // column validation

    for(int i = 0;i < 9;i++)
    {
        if(puzzle[i][col] == val)
        {
            return 0;
        }
    }

    // squares validation

    int r = row - row % 3;
    int c = col - col % 3;

    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(puzzle[r + i][c + j] == val)
            {
                return 0;
            }
        }
    }

        return 1;
}

int solve_puzzle(int puzzle[9][9] , int row , int col)
{

    if(col == 9)
    {
        if(row == 8)
        {
            return 1;
        }
            row++;
            col = 0;
    }

    if(puzzle[row][col] > 0)
    {
        return solve_puzzle(puzzle , row , col + 1);
    }

    for(int i = 1;i<=9;i++)
    {
        if(valid_move(puzzle , row , col , i))
        {
            puzzle[row][col] = i;
            if(solve_puzzle(puzzle , row , col + 1))
            {
                return 1;
            }
                puzzle[row][col] = 0;
        }
    }

        return 0;
}