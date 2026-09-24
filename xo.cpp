#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        cout << board[i][0] << " | "
             << board[i][1] << " | "
             << board[i][2] << endl;

        if (i < 2)
            cout << "--|---|--" << endl;
    }
}

bool checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

int main()
{
    char player = 'X';
    int choice;

    while (true)
    {
        printBoard();

        cout << "Player " << player << ", choose a cell: ";
        cin >> choice;

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid choice!" << endl;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Cell is already taken!" << endl;
            continue;
        }

        board[row][col] = player;

        if (checkWin(player))
        {
            printBoard();
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (isDraw())
        {
            printBoard();
            cout << "Draw!" << endl;
            break;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}
