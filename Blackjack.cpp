#include "stdafx.h"
#include "Blackjack.h"

Blackjack::Blackjack()
{
    srand(time(0));
    dealerhandSize = 0;
    playerhandSize = 0;
    dealerhandSum = 0;
    playerhandSum = 0;
    playerDone = false;
    dealerDone = false;
}

void Blackjack::playGame()
{
    cout << "Welcome to Blackjack!\n";

    // Start the player and dealer with two cards
    addPlayerCard();
    addPlayerCard();
    addDealerCard();
    addDealerCard();
    sumHands();
    printHand();

    if (dealerhandSum == 21)
    {
        cout << "BLACKJACK FOR DEALER. Dealer wins.\n";
        return;
    }
    else if (playerhandSum == 21)
    {
        cout << "BLACKJACK FOR PLAYER. Player wins.\n";
        return;
    }

    while (dealerDone == false || playerDone == false)
    {
        if (playerDone == false)
        {
            cout << "Hit? (1 - Yes, 2 - No)\n";
            cin >> playerhit;

            if (playerhit == 1)
            {
                addPlayerCard();
                printHand();
                sumHands();

                if (playerhandSum > 21)
                {
                    cout << "Player's hand exceeded 21. Player loses.\n";
                    return;
                }
            }
        }

        if (playerDone == false)
        {
            cout << "Would you like to stand? (1 - Yes, 2 - No)\n";
            cin >> playerstand;
        }

        if (playerstand == 1)
        {
            playerDone = true;
        }

        if (dealerhandSum < 17 && dealerDone != true)
        {
            addDealerCard();
            printHand();
            sumHands();

            if (dealerhandSum > 21)
            {
                cout << "Dealer hand exceeded 21. Dealer loses.\n";
                return;
            }
        }
        else if (dealerhandSum >= 17)
        {
            dealerDone = true;
        }

        if (playerhandSum == 21 && dealerhandSum == 21)
        {
            cout << "Push, player and dealer reached 21.\n";
            return;
        }
        else if (playerhandSum == 21)
        {
            cout << "Player reached 21. Player wins.\n";
            return;
        }
        else if (dealerhandSum == 21)
        {
            cout << "Dealer reached 21. Dealer wins.\n";
            return;
        }

        if ((playerDone == true && dealerDone == true) || (playerhandSize == 5 && playerhandSize == 5))
        {
            if (dealerhandSum < playerhandSum)
            {
                cout << "Sum of your hand exceeds the dealer's sum of " << dealerhandSum << "! You win!";
                return;
            }
            else if (playerhandSum == dealerhandSum)
            {
                cout << "Dealer sum of " << dealerhandSum << " is equal to the sum of your hand. Tie game.";
                return;
            }
            else if (dealerhandSum > playerhandSum)
            {
                cout << "Sum of your hand is lower than the dealer's sum of " << dealerhandSum << ". You lose!";
                return;
            }
        }
    }
}

int dealerhand[5];
int playerhand[5];
int dealerhandSize;
int playerhandSize;
int dealerhandSum;
int playerhandSum;
int playerhit;
int playerstand;
bool playerDone;
bool dealerDone;

void Blackjack::addPlayerCard()
{
    if (playerhandSize <= 5)
    {
        playerhand[playerhandSize] = 1 + (rand() % 11);
        playerhandSize++;
    }
    else
    {
        cout << "Sorry. You have reached the maximum number of cards (5)." << endl;
        playerDone = true;
    }
}

void Blackjack::addDealerCard()
{
    if (dealerhandSize <= 5)
    {
        dealerhand[dealerhandSize] = 1 + (rand() % 11);
        dealerhandSize++;
    }
    else
    {
        dealerDone = true;
    }
}

void Blackjack::printHand()
{
    cout << "Your current hand is...\n";

    for (int i = 0; i < playerhandSize; i++)
    {
        cout << "    -" << playerhand[i] << "-    \n\n";
    }

    cout << "Dealer's current hand is...\n";

    for (int j = 0; j < dealerhandSize; j++)
    {
        cout << "    -" << dealerhand[j] << "-    \n\n";
    }
}

void Blackjack::sumHands()
{
    dealerhandSum = 0;
    playerhandSum = 0;
    for (int i = 0; i < dealerhandSize; i++)
    {
        dealerhandSum += dealerhand[i];
    }

    for (int j = 0; j < playerhandSize; j++)
    {
        playerhandSum += playerhand[j];
    }

    cout << "Current player hand sum is: " << playerhandSum << endl;
}