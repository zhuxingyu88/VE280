/*
 * VE280 Lab 3, SU2020.
 * Written by Guoxin Yin
 */

#include <iostream>

using namespace std;

const int MAXSIZE = 10;

bool canWin_helper(int count, int arr[], int position, bool (&face)[MAXSIZE]) {
    if (position >= count || position < 0 || !face[position]) return false;
    else {
        if (arr[position] == 280) return true;
        else {
            face[position] = false;
            return canWin_helper(count, arr, arr[position] + position, face) || canWin_helper(count, arr, position - arr[position],face);
        }
    }

}

bool canWin(int count, int arr[], int position) {
    // EFFECTS: return whether the player can win given the start position
    // and the card sequence

    // TODO: implement this function
    bool face[MAXSIZE];
    for (int i = 0; i < MAXSIZE; ++i) face[i] = true;
    return canWin_helper(count, arr, position, face);
}

int main() {
    int count;
    cin >> count;
    int arr[MAXSIZE];
    for (int i = 0; i < count; ++i) {
        cin >> arr[i];
    }
    int position;
    cin >> position;
    cout << canWin(count, arr, position);
}