/*
 * This is an exercise of VE280 Lab 1, SU2020.
 * Written by Martin Ma.
 * Latest Update: 5/10/2020.
 * Copyright © 2020 Mars-tin. All rights reserved.
 */

#include <iostream>
using namespace std;


// EFFECTS: return the trace of the Laplacian of the weight matrix.
int traceLaplacian(int weight[][50], int size){
    // TODO: Implement this function.
    int degree[50][50] = {{0}};
    int laplacian[50][50];
    int trace = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            degree[i][i] += weight[i][j];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            laplacian[i][j] = degree[i][j] - weight[i][j];
    for (int k = 0; k < size; ++k)
        trace += laplacian[k][k];
    return trace;
}


int main(){
    int size, trace;
    int weight[50][50] = {};
    cin >> size;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            cin >> weight[i][j];
    trace = traceLaplacian(weight, size);
    cout << trace << endl;
}
