#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char tic_tac_toe_board[3][3] = {{' ', ' ', ' '}, // Creating a global board so we can easily access the board
                                {' ', ' ', ' '},
                                {' ', ' ', ' '}};

void initialize_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tic_tac_toe_board[i][j] = ' ';
        }
    }
}

void print_tic_tac_toe_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Drawing Graphics on the board
            if (j < 1)
                cout << " " << tic_tac_toe_board[i][j] << " | ";
            else if (j < 2)
                cout << tic_tac_toe_board[i][j] << " | ";
            else
                cout << tic_tac_toe_board[i][j];
        }
        (i < 2) ? cout << "\n---|---|---" << endl : cout << endl;
    }
}

void getInput(int player)
{
    int row, column;

    // Error Checking
    while (true)
    {
        cout << "Row: ";
        cin >> row;

        cout << "Column: ";
        cin >> column;

        if (row > 3 || row < 1 || column > 3 || column < 1)
        {
            cout << "Invalid Choice! try again\n";
        }
        else if (tic_tac_toe_board[row - 1][column - 1] != ' ')
        {
            cout << "That space is taken! try again\n";
        }
        else
        {
            break;
        }
    }

    if (player == 1)
    {
        tic_tac_toe_board[row - 1][column - 1] = 'X';
    }
    else if (player == 2)
    {
        tic_tac_toe_board[row - 1][column - 1] = 'O';
    }
}

void player_1_turn()
{
    getInput(1);

    print_tic_tac_toe_board();
}

void player_2_turn()
{
    getInput(2);

    print_tic_tac_toe_board();
}

bool winning_condition(int player)
{
    char sign;
    (player == 1) ? sign = 'X' : sign = 'O';

    if (tic_tac_toe_board[0][0] == sign && tic_tac_toe_board[0][1] == sign && tic_tac_toe_board[0][2] == sign)
    {
        return true;
    }
    else if (tic_tac_toe_board[1][0] == sign && tic_tac_toe_board[1][1] == sign && tic_tac_toe_board[1][2] == sign)
    {
        return true;
    }
    else if (tic_tac_toe_board[2][0] == sign && tic_tac_toe_board[2][1] == sign && tic_tac_toe_board[2][2] == sign)
    {
        return true;
    }
    else if (tic_tac_toe_board[0][0] == sign && tic_tac_toe_board[1][0] == sign && tic_tac_toe_board[2][0] == sign)
    {
        return true;
    }
    else if (tic_tac_toe_board[0][1] == sign && tic_tac_toe_board[1][1] == sign && tic_tac_toe_board[2][1] == sign)
    {
        return true;
    }
    else if (tic_tac_toe_board[0][2] == sign && tic_tac_toe_board[1][2] == sign && tic_tac_toe_board[2][2] == sign)
    {
        return true;
    }
    else if (tic_tac_toe_board[0][0] == sign && tic_tac_toe_board[1][1] == sign && tic_tac_toe_board[2][2] == sign)
    {
        return true;
    }
    else if (tic_tac_toe_board[0][2] == sign && tic_tac_toe_board[1][1] == sign && tic_tac_toe_board[2][0] == sign)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool drawing_condition()
{
    bool draw = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tic_tac_toe_board[i][j] == ' ')
            {
                draw = false;
            }
        }
    }

    if (draw)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int score_1, score_2;

    ifstream readFile("scores.txt");

    readFile.ignore(9, ' '); // Skipping the "Player-1: " string

    readFile >> score_1; // and only reading the int(score)

    readFile.ignore(9, ' ');

    readFile >> score_2;

    readFile.close();

    while (true)
    {
        int current_player = 1;

        while (true) // gameloop
        {
            if (current_player == 1)
            {
                cout << "Player 1's turn!\n";
                player_1_turn();
            }
            else if (current_player == 2)
            {
                cout << "Player 2's turn!\n";
                player_2_turn();
            }

            if (winning_condition(current_player))
            {
                cout << "Player " << current_player << " wins!";
                break;
            }
            else if (drawing_condition())
            {
                cout << "Draw!";
                break;
            }

            (current_player == 1) ? current_player = 2 : current_player = 1; // passing turns
        }

        initialize_board();
        (current_player == 1) ? score_1++ : score_2++;

        cout << "\n\nCurrent scores:";
        cout << "\nPlayer 1: " << score_1;
        cout << "\nPlayer 2: " << score_2;

        char retry;

        cout << "\nRetry?(y or n) ";
        cin >> retry;

        if (retry == 'n')
        {
            break;
        }
    }

    ofstream writeFile("scores.txt");

    writeFile << "Player-1: " << score_1;
    writeFile << "\nPlayer-2: " << score_2;

    writeFile.close();

    return 0;
}