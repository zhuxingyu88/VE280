//
// Created by 17432 on 2020/6/21.
//

#include <iostream>
#include "card.h"
#include "hand.h"

using namespace std;

int main()
{

    Card card1, card2, card3;
    int result = 0;
    Hand a = Hand();

    card1.suit = SPADES;
    card1.spot = ACE;

    card2.suit = HEARTS;
    card2.spot = ACE;

    card3.suit = CLUBS;
    card3.spot = KING;

    a.addCard(card1);
    cout << a.handValue().count << endl;
    a.addCard(card2);
    cout << a.handValue().count << endl;
    a.addCard(card3);
    cout << a.handValue().count << endl;

    if ((a.handValue().count != 12) || (a.handValue().soft != false)) {
        cout << "Cards don't match: TEST FAILED\n";
        result = -1;
    }

    return result;
}
