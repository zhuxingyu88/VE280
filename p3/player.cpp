#include "player.h"

class Simple_Player: public Player {
    // simple player class
 public:
    virtual int bet(unsigned int bankroll, unsigned int minimum);
    // REQUIRES: bankroll >= minimum
    // EFFECTS: return minimum

    bool draw(Card dealer, const Hand &player);
    // EFFECTS: returns true if the player wishes to be dealt another
    // card, false otherwise.

    virtual void expose(Card c);

    virtual void shuffled();
};

class Counting_Player: public Simple_Player{
    // counting player class
    int count;

 public:
    Counting_Player();
    // EFFECTS: constructor for Counting_Player
    // MODIFIES: count

    int bet(unsigned int bankroll, unsigned int minimum);
    // REQUIRES: bankroll >= minimum
    // EFFECTS: return minimum or 2 * minimum

    void expose(Card c);
    // EFFECTS: allows the player to "see" the newly-exposed card c.

    void shuffled();
    // EFFECTS: tells the player that the deck has been re-shuffled.
    // MODIFIES: count
};



int Simple_Player::bet(unsigned int bankroll, unsigned int minimum) {
    return (int)minimum;
}

bool Simple_Player::draw(Card dealer, const Hand &player) {
    if (!player.handValue().soft) {
        if (player.handValue().count <= 11)
            return true;
        else if (player.handValue().count == 12)
            return !(dealer.spot == FOUR || dealer.spot == FIVE || dealer.spot == SIX);
        else if (player.handValue().count >= 13 && player.handValue().count <= 16)
            return !(dealer.spot >= TWO && dealer.spot <=SIX);
        else
            return false;
    } else {
        if (player.handValue().count <= 17)
            return true;
        else if (player.handValue().count == 18)
            return !(dealer.spot == TWO || dealer.spot == SEVEN || dealer.spot == EIGHT);
        else
            return false;
    }
}

void Simple_Player::expose(Card c) {}
void Simple_Player::shuffled() {}

Counting_Player::Counting_Player():count(0) {}

int Counting_Player::bet(unsigned int bankroll, unsigned int minimum) {
    if (count >= 2 && bankroll >= 2 * minimum)
        return (int)(2 * minimum);
    else
        return (int)minimum;
}

void Counting_Player::expose(Card c) {
    if (c.spot >= TEN && c.spot <= ACE)
        --count;
    else if (c.spot >= TWO && c.spot <= SIX)
        ++count;
}

void Counting_Player::shuffled() {
    count = 0;
}

static Simple_Player simplePlayer = Simple_Player();
static Counting_Player countingPlayer = Counting_Player();

extern Player *get_Simple() {
    return &simplePlayer;
}

extern Player *get_Counting() {
    return &countingPlayer;
}