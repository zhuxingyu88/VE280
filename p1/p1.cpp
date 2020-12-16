#include <iostream>
#include <cmath>
#include <string>
using namespace std;

 // test the validity of inputs
void get_input(int&  i, int&  case_num){
     for (; true; ) {
             cout << "Please enter the integer and the test number: ";
             cin >> i;
             cin >> case_num;
             if (i > 0 && i <= 10000000 && case_num >=1 && case_num <= 4 ) break;
         }
}

 // whether i is a triangle number
bool triangle_test(const int* i) {
    int n = sqrt(*i * 2); // calculate the possible n
    return n * (n + 1) / 2 == *i;
}

 // whether i is a palindrome
bool palindrome_test(const int* i) {
    string str = to_string(*i); // cast i into string
    string rev_str; // reverse the string
    for (int j = 0; j < (int)str.length(); ++j)
        rev_str += str[str.length()-j-1];
    return str == rev_str;
}

 // whether i is a power number
bool power_test(const int* i) {
    const int MAX_M = sqrt(*i);
    for (int j = 2; j <= MAX_M; ++j)
        if (abs(round(log(*i)/log(j)) - log(*i)/log(j)) < 0.000000000000001) return true; // whether log(*i)/log(j) is integer
    return false;
}

 // whether i is an abundant number
bool abundant_test(const int* i) {
    int sum = 0;
    const int MAX_DIVISOR = *i/2; //calculate the possible max divisor
    for (int j = 1; j <= MAX_DIVISOR; ++j)
        if (abs(*i/j - (float)*i/(float)j) < 0.000000000000001) sum += j;
    cout << sum <<endl;
    return sum > *i;
}

int main() {
    int i, case_num; // i stands for the integer and case_num stands for the tested case
    get_input(i, case_num);
    switch (case_num) {
        case 1: cout << triangle_test(&i) << endl;
            break;
        case 2: cout << palindrome_test(&i) << endl;
            break;
        case 3: cout << power_test(&i) << endl;
            break;
        case 4: cout << abundant_test(&i) << endl;
            break;
        default:
            break;
    }
    return 0;
}
