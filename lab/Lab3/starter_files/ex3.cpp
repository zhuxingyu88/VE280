#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int add(int count, const int array[]){
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += array[i];
    }
    return sum;
}

int small(int count, const int array[]){
    int least = array[0];
    for (int i = 1; i < count; ++i) {
        if (least > array[i]) least = array[i];
    }
    return least;
}

int main(int argc, char *argv[]) {
    bool addflag = false;
    bool smallflag = false;
    bool verboseflag = false;
    int n = 0;
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            string a = argv[i];
            if (a == "--help") {
                cout << "Hey, I love Integers." << endl;
                return 0;
            } else if (a == "--add") {
                addflag = true;
                continue;
            } else if (a == "--small") {
                smallflag = true;
                continue;
            } else if (a == "--verbose") {
                verboseflag = true;
                continue;
            }
        } else n = atoi(argv[i]);
    }
    if (!addflag && !smallflag){
        cout << "No work to do!" << endl;
        return 0;
    }
    int count;
    int array[100] = {0};
    cin >> count;
    for (int j = 0; j < count; ++j) {
        cin >> array[j];
    }
    if (addflag) {
        if (verboseflag) {
            cout << "This is add operation." << endl;
            cout << add(count,array) << endl;
        } else{
            cout << add(count,array) << endl;
        }
    }
    if (smallflag) {
        if (verboseflag) {
            cout << "This is small operation." << endl;
            cout << small(count,array) + n << endl;
        } else{
            cout << small(count,array) + n << endl;
        }
    }
    return 0;
}
