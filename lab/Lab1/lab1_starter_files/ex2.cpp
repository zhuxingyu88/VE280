/*
 * This is an exercise of VE280 Lab 1, SU2020.
 * Written by Martin Ma.
 * Latest Update: 5/10/2020.
 * Copyright © 2020 Mars-tin. All rights reserved.
 */

#include <iostream>
using namespace std;


// EFFECTS: return true if the password is a valid one
bool isValidPassword(char password[]){
    // TODO: Implement this function.
    bool alpha_flag = false;
    bool numer_flag = false;
    bool non_flag = false;
    for (int i = 0; password[i] ; ++i) {
        if (!alpha_flag) alpha_flag = isalpha(password[i]);
        if (!numer_flag) numer_flag = isdigit(password[i]);
        if (!non_flag) non_flag = !isalnum(password[i]);
        if (alpha_flag && numer_flag && non_flag) break;
    }
    return alpha_flag && numer_flag && non_flag;
}


int main(){
    char password[50] = {};
    cin >> password;
    cout << isValidPassword(password) << endl;
}
