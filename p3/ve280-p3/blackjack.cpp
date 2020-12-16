#include <iostream>
#include <string>

#include "player.h"
#include "deck.h"
#include "rand.h"

using namespace std;

void initial_shuffle(Deck& deck, Player* player) {
    // EFFECTS: shuffle the deck at the begin of each hand
    // MODIFIES: deck player
    cout << "Shuffling the deck\n";
    int n; // random number
    for (int i = 0; i < 7; ++i) {
        n = get_cut();
        deck.shuffle(n);
        cout << "cut at " << n << endl;
    }
    player->shuffled();
}

Card deal_card(Deck& deck, Hand& hand, Player* player, bool announce, bool is_player) {
    // EFFECTS: deal one card. announce to player if announce
    // MODIFIES: deck hand player
    Card temp_card = deck.deal();
    hand.addCard(temp_card);
    if (is_player) {
        player->expose(temp_card);
        cout << "Player dealt " << SpotNames[temp_card.spot] << " of " << SuitNames[temp_card.suit] << endl;
    } else if (announce) {
        player->expose(temp_card);
        cout << "Dealer dealt " << SpotNames[temp_card.spot] << " of " << SuitNames[temp_card.suit] << endl;
    }
    return temp_card;
}

void deal_4(Deck& deck, Hand& player_hand, Hand& dealer_hand, Player* player, Card* up, Card* hole) {
    // EFFECTS: deal four cards at the beginning of each hand
    // MODIFIES: up hole deck hand player
    deal_card(deck, player_hand, player, true, true);
    *up = deal_card(deck, dealer_hand, player, true, false);
    deal_card(deck, player_hand, player, true, true);
    *hole = deal_card(deck, dealer_hand, player, false, false);
}

void hand_sim(unsigned int hands_to_play, unsigned int& hands, unsigned int& bankroll, Deck& deck, Player* player,
        Hand& player_hand, Hand& dealer_hand) {
    // EFFECTS: simulate the hands
    // MODIFIES: hands bankroll deck player hand
    int bet;
    const int MINIMUM_BET = 5;
    Card up{}, hole{};
    while (hands < hands_to_play && bankroll >= MINIMUM_BET){
        ++hands;
        player_hand.discardAll();
        dealer_hand.discardAll();
        cout << "Hand " << hands << " bankroll " << bankroll << endl;
        if (deck.cardsLeft() < 20){
            initial_shuffle(deck, player);
            player->shuffled();
        }
        bet = player->bet(bankroll, MINIMUM_BET);
        cout << "Player bets " << bet << endl;
        deal_4(deck, player_hand, dealer_hand, player, &up, &hole);
        // natual 21
        if (player_hand.handValue().count == 21){
            bankroll += bet / 2;
            cout << "Player dealt natural 21\n";
            continue;
        }
        while (player->draw(up, player_hand))
            deal_card(deck, player_hand, player, true, true);
        cout << "Player's total is " << player_hand.handValue().count << endl;
        // bust
        if (player_hand.handValue().count > 21) {
            cout << "Player busts\n";
            bankroll -= bet;
            continue;
        }
        cout << "Dealer's hole card is " << SpotNames[hole.spot] << " of " << SuitNames[hole.suit] << endl;
        player->expose(hole);
        // dealer's hand
        while (dealer_hand.handValue().count < 17)
            deal_card(deck, dealer_hand, player, true, false);
        cout << "Dealer's total is " << dealer_hand.handValue().count << endl;
        if (dealer_hand.handValue().count > 21) {
            cout << "Dealer busts\n";
            bankroll += bet;
            continue;
        }
        if (player_hand.handValue().count > dealer_hand.handValue().count) {
            cout << "Player wins\n";
            bankroll += bet;
        } else if (player_hand.handValue().count == dealer_hand.handValue().count) {
            cout << "Push\n";
        } else {
            cout << "Dealer wins\n";
            bankroll -= bet;
        }

    }
}

int main(int argc, char* argv[]) {
    // initialization
    unsigned int bankroll, hands_to_play, hands;
    string player_type;
    Deck deck;
    Player* player;
    Hand player_hand, dealer_hand;
    hands = 0;

    bankroll = atoi(argv[1]);
    hands_to_play = atoi(argv[2]);
    player_type = argv[3];
    // player type
    if (player_type == "simple")
        player = get_Simple();
    else
        player = get_Counting();
    initial_shuffle(deck, player);
    hand_sim(hands_to_play, hands, bankroll, deck, player, player_hand, dealer_hand);
    cout << "Player has " << bankroll << " after " << hands << " hands\n";
}