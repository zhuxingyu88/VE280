#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef struct apple_T {
    string name;
    double price;
    double weight;
    apple_T(const string& name, double price, double weight) {
        this->name = name;
        this->price = price;
        this->weight = weight;
    }
} apple;

int main(int argc, char* argv[]) {
    ifstream iFile;
    iFile.open(argv[1]);
    string line;
    string name;
    double price;
    double weight;

    getline(iFile, line);
    istringstream iStream;
    iStream.str(line);
    iStream >> name >> price >> weight;
    iStream.clear();
    apple cheapest_apple = apple_T(name, price, weight);

    while (getline(iFile, line)) {
        iStream.str(line);
        iStream >> name >> price >> weight;
        iStream.clear();
        if (price/weight < cheapest_apple.price/cheapest_apple.weight) {
            cheapest_apple = apple_T(name, price, weight);
        }
    }
    cout << cheapest_apple.name << ' ' ;
    cout << setiosflags(ios::fixed) << setprecision(2) << cheapest_apple.price << ' ';
    cout << cheapest_apple.weight << endl;
    iFile.close();
    return 0;
}

