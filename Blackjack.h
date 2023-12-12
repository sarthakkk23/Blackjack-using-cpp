#pragma once
#include "stdafx.h"

class Blackjack
{
public:
    Blackjack();
    void playGame();
private:
    int dhand[5];
    int phand[5];
    int dealerhandSize;
    int playerhandSize;
    int dealerhandSum;
    int playerhandSum;
    int playerhit;
    int playerstand;
    bool playerDone;
    bool dealerDone;
    void addPlayerCard();
    void addDealerCard();
    void printHand();
    void sumHands();
};