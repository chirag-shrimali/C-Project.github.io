#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define BOARD_SIZE 3
#define X 'X'
#define O 'O'

using namespace std;

typedef struct
{
    int player;
    int computer;
    int draw;
} Score;

int choice_diff; // choices of difficulty
Score score = {.player = 0, .computer = 0, .draw = 0};

// prototypes
void take_input();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE]);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);
void pause_console();

int main()
{
    char choice;
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "\n+-------------------------------------------+";
    cout << "\n|        TIC TAC TOE GAMES : LEGENDS        |";
    cout << "\n+-------------------------------------------+" << endl;

    take_input();

    clear_screen();

    cout << "\n+-------------------------------------------+";
    cout << "\n|        TIC TAC TOE GAMES : LEGENDS        |";
    cout << "\n+-------------------------------------------+" << endl;

    do {
        play_game();

        // Let the user see the final board/result before continuing
        pause_console();

        // clear any leftover input before reading the choice
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nCan You Play Again? ('y' or 'Y' for Yes , 'n' or 'N' for No) : ";
        cin >> choice;

        if (choice == 'N' || choice == 'n')
        {
            cout << "\nThanks for Playing TIC TAC TOE GAMES : LEGENDS" << endl;
            return 0;
        }

        clear_screen();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void take_input()
{
    while (true)
    {
        cout << "\nChoose Your Challenge : ";
        cout << "\n1. The Challenger (Human - Standard)";
        cout << "\n2. God Mode (Difficult to Win!!)";
        cout << "\nEnter Your Choice for the Challenge (1/2) : ";

        if (!(cin >> choice_diff))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Please enter 1 or 2." << endl;
            continue;
        }

        if (choice_diff == 1 || choice_diff == 2)
            break;

        cout << "\nInvalid Choice! Please choose 1 or 2." << endl;
    }
}

void clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    cout << "\nScore - Player X : " << score.player
         << " , Computer : " << score.computer
         << " , Draws : " << score.draw << endl;

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        cout << "\n";
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            cout << " " << board[row][col] << " ";
            if (col < BOARD_SIZE - 1)
                cout << "|";
        }
        if (row < BOARD_SIZE - 1)
            cout << "\n---+---+---";
    }
    cout << "\n\n";
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    // Check rows and columns
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
            return 1;
        if (board[0][row] == player && board[1][row] == player && board[2][row] == player)
            return 1;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;

    return 0;
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++)
        for (int col = 0; col < BOARD_SIZE; col++)
            if (board[row][col] == ' ')
                return 0;
    return 1;
}

void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    clear_screen();   // only clear when a new game begins

    char current_player = (rand() % 2 == 0) ? X : O;

    print_board(board);

    while (true)
    {
        if (current_player == X)
        {
            player_move(board);
            print_board(board);

            if (check_win(board, X))
            {
                score.player++;
                print_board(board);
                cout << "\nPlayer - X Wins!!" << endl;
                break;
            }
            current_player = O;
        }
        else
        {
            computer_move(board);
            print_board(board);

            if (check_win(board, O))
            {
                score.computer++;
                print_board(board);
                cout << "\nPlayer - O Wins!!" << endl;
                break;
            }
            current_player = X;
        }

        if (check_draw(board))
        {
            score.draw++;
            print_board(board);
            cout << "\nIt's a Draw!!" << endl;
            break;
        }
    }
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    if (row < 1 || row > 3 || col < 1 || col > 3)
        return 0;
    if (board[row - 1][col - 1] != ' ')
        return 0;
    return 1;
}

void player_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;

    while (true)
    {
        cout << "\nPlayer - X's Turn.";
        cout << "\nEnter row and column (1 - 3) for X : ";

        if (!(cin >> row >> col))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input! Please enter numbers only (1-3)." << endl;
            continue;
        }

        if (!is_valid_move(board, row, col))
        {
            cout << "\nInvalid move! Please enter row & column between 1 and 3 for an empty spot." << endl;
            continue;
        }

        board[row - 1][col - 1] = X;
        break;
    }
}

void computer_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    // immediate wins
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == ' ')
            {
                board[row][col] = O;
                if (check_win(board, O))
                    return;
                board[row][col] = ' ';
            }
        }
    }

    // immediate block
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == ' ')
            {
                board[row][col] = X;
                if (check_win(board, X))
                {
                    board[row][col] = O;
                    return;
                }
                board[row][col] = ' ';
            }
        }
    }

    // god mode strategy
    if (choice_diff == 2)
    {
        // play center if possible
        if (board[1][1] == ' ')
        {
            board[1][1] = O;   // <-- fixed assignment
            return;
        }

        // play corners if possible
        int corner[4][2] = {
            {0, 0},
            {0, 2},
            {2, 0},
            {2, 2},
        };

        for (int i = 0; i < 4; i++)
        {
            if (board[corner[i][0]][corner[i][1]] == ' ')
            {
                board[corner[i][0]][corner[i][1]] = O;
                return;
            }
        }
    }

    // fallback available move
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == ' ')
            {
                board[row][col] = O;
                return;
            }
        }
    }
}

void pause_console()
{
    #ifdef _WIN32
        // On Windows, system("pause") will wait for a keypress
        cout << "\n(Press any key to continue...)";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("pause");
    #else
        // On Unix-like systems, wait for Enter
        cout << "\n(Press Enter to continue...)";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    #endif
}
