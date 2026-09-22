```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int rounds;
    int playerScore = 0;
    int computerScore = 0;

    cout << "=== Rock, Paper, Scissors ===" << endl;
    cout << "How many rounds? ";
    cin >> rounds;

    for (int i = 1; i <= rounds; i++)
    {
        char player;
        char computer;

        cout << "\nRound " << i << endl;

        cout << "Enter your choice (r/p/s): ";
        cin >> player;

        while (player != 'r' && player != 'p' && player != 's')
        {
            cout << "Invalid choice. Enter r, p, or s: ";
            cin >> player;
        }

        int randomChoice = rand() % 3;

        if (randomChoice == 0)
            computer = 'r';
        else if (randomChoice == 1)
            computer = 'p';
        else
            computer = 's';

        cout << "You chose ";

        if (player == 'r')
            cout << "Rock";
        else if (player == 'p')
            cout << "Paper";
        else
            cout << "Scissors";

        cout << ". Computer chose ";

        if (computer == 'r')
            cout << "Rock." << endl;
        else if (computer == 'p')
            cout << "Paper." << endl;
        else
            cout << "Scissors." << endl;

        if (player == computer)
        {
            cout << "It's a tie!" << endl;
        }
        else if ((player == 'r' && computer == 's') ||
                 (player == 'p' && computer == 'r') ||
                 (player == 's' && computer == 'p'))
        {
            cout << "You win this round!" << endl;
            playerScore++;
        }
        else
        {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        }

        cout << "Score -> You: " << playerScore
             << " Computer: " << computerScore << endl;
    }

    cout << "\n=== Final Result ===" << endl;
    cout << "You: " << playerScore
         << " | Computer: " << computerScore << endl;

    if (playerScore > computerScore)
        cout << "You win overall!" << endl;
    else if (computerScore > playerScore)
        cout << "Computer wins overall!" << endl;
    else
        cout << "It's a tie overall!" << endl;

    return 0;
}
