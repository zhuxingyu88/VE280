/*
 * Lab2 Ex1 VE280 20SU
 * Created by: Yiqing Fan
 * Last update: May 25, 2020
 */

#include <iostream>

using namespace std;

#define RANGE 100000

bool isPrime[RANGE + 1];

// MODIFIES: isPrime[]
// EFFECTS: fill in isPrime[], true for prime, false otherwise
void generateIsPrime() {
    // TODO: implement Eratosthenes Sieve Algorithm
    isPrime[0] = false;
    isPrime[1] = false;
    for (int k = 2; k <= RANGE; ++k) {
        isPrime [k] = true;
    }
    for (int i = 2; i <= RANGE/2; ++i)
        for (int j = 2; j*i <= RANGE; ++j)
            isPrime[i * j] = false;
}

int main() {
    // TODO: generate lookup table
    generateIsPrime();
    // TODO: read input and check if each num is prime
    int len, cursor, number, num[20];
    cursor = 0;
    cin >> len;
    for (int i = 0; i < len; ++i) {
        cin >> number;
        if (isPrime[number]) {
            num[cursor] = number;
            cursor++;
        }
    }
    if (cursor != 0) {
        for (int j = 0; j < cursor - 1; ++j) {
            cout << num[j] << " ";
        }
        cout << num[cursor - 1] << endl;
    }
    return 0;
}