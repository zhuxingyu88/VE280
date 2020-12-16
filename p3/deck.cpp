#include "deck.h"

Deck::Deck(): next(0) {
    // constructor of Deck
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck[i * 13 + j].suit = (Suit)(i);
            deck[i * 13 + j].spot = (Spot)(j);
        }
    }
}

void Deck::reset() {
    // reset deck[] and next = 0
    next = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck[i * 13 + j].suit = (Suit)(i);
            deck[i * 13 + j].spot = (Spot)(j);
        }
    }
}

void Deck::shuffle(int n) {
    // split into 0 - n-1 and n - DeckSize
    next = 0;
    Card deck1[DeckSize];
    if (n <= DeckSize/2) {
        for (int i = 0; i < n; ++i) {
            deck1[2 * i] = deck[i + n];
            deck1[2 * i + 1] = deck[i];
        }
        for (int j = 2 * n; j < DeckSize; ++j) {
            deck1[j] = deck[j];
        }
    } else {
        for (int i = 0; i < DeckSize - n; ++i) {
            deck1[2 * i] = deck[i + n];
            deck1[2 * i + 1] = deck[i];
        }
        for (int j = DeckSize - n; j < n; ++j) {
            deck1[j + DeckSize - n] = deck[j];
        }
    }
    for (int k = 0; k < DeckSize; ++k) {
        deck[k] = deck1[k];
    }
}

Card Deck::deal() {
    // deal one card
    if (next >= DeckSize) {
        DeckEmpty deckEmpty;
        throw deckEmpty;
    }
    return deck[next++];
}

int Deck::cardsLeft() {
    // DeckSize - next
    return DeckSize - next;
}

