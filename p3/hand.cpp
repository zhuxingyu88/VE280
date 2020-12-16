# include "hand.h"

Hand::Hand() {
    // constructor
    curValue.count = 0;
    curValue.soft = false;
}

void Hand::discardAll() {
    // restore the initial state
    curValue.count = 0;
    curValue.soft = false;
}

void Hand::addCard(Card c) {
    // ace and soft state should be considered independently
    if (c.spot <= NINE){ // TWO to NINE
        curValue.count += (c.spot + 2);
        if (curValue.count > 21 && curValue.soft){
            curValue.soft = false;
            curValue.count -= 10;
        }
    } else if (c.spot <= KING && c.spot >= TEN) { // TEN to KING
        curValue.count += 10;
        if (curValue.count > 21 && curValue.soft){
            curValue.soft = false;
            curValue.count -= 10;
        }
    } else { // ACE
        if (curValue.soft){ // already soft
            curValue.count += 1;
        } else{ // hard
            if (curValue.count + 11 <= 21){ // turn to soft
                curValue.count += 11;
                curValue.soft = true;
            } else { // still hard
                curValue.count += 1;
            }
        }
    }
}

HandValue Hand::handValue() const {
    // return curValue
    return curValue;
}

