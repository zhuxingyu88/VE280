#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    istringstream iStream;
    ostringstream oStream;
    string line, name;
    int n = 0;
    getline(cin, line);
    for (int i = 0; i < (int ) line.length(); ++i ) {
        if (line[i] == ',') {
            line[i] = ' ';
            ++n;
        }
    }
    iStream.str(line);
    for (int j = 0; j <= n ; ++j) {
        iStream >> name;
        cout << name << endl;
    }
    cout << n+1 << endl;
    return 0;
}
