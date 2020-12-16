#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int min = atoi(argv[1]);
    int max = atoi(argv[1]);
    int n = 0;
    for (int i = 1; i < argc; ++i) {
        n = atoi(argv[i]);
        if (n > max)
            max = n;
        if (n < min)
            min = n;
    }
    for (int j = 1; j < argc; ++j) {
        n = atoi(argv[j]);
        if (n == max || n == min)
            continue;
        else
            cout << n << ' ';
    }
    cout << endl;
    return 0;
}
