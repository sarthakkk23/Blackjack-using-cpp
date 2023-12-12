#include "stdafx.h"
#include "Blackjack.h"

int main()
{
    int exitGame = 1;
    do
    {
        Blackjack casino_royale;
        casino_royale.playGame();
        cout << "\nWould you like to play again? (1 - Yes, 2 - No)\n";
        cin >> exitGame;
    }while (exitGame == 1);
    cout << "\nThanks for playing!\n";
    system("pause");
    return 0;
}