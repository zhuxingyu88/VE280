//
// Created by 朱星宇 on 2020/7/22.
//

#include <iostream>
#include <sstream>
#include "dlist.h"

using namespace std;

class parenthesis_mismatch {
    // OVERVIEW: an exception class
};

class not_enough_operands {
    // OVERVIEW: an exception class
};

class divide_by_zero {
    // OVERVIEW: an exception class
};

class too_many_operands {
    // OVERVIEW: an exception class
};

template <class T>
struct Stack_t {
    // OVERVIEW: contains a double-ended list of T, act as a stack

    Dlist<T> list; // The double ended linked list

    // MODIFIES list
    // EFFECTS inserts o at the front of the list
    void push(T object) {
        T* op = new T(object);
        list.insertFront(op);
    }

    // MODIFIES list
    // EFFECTS removes and returns first object from non-empty list
    //         throws an instance of emptyList if empty
    void pop() {
        delete list.removeFront();
    }

    // EFFECTS return a reference to the object in the first node
    T top() {
        T* op = list.removeFront();
        T result = *op;
        list.insertFront(op);
        return result;
    }

    // EFFECTS return whether the list is empty
    bool empty() {
        return list.isEmpty();
    }
};

// MODIFIES stack
// EFFECTS convert infix to RPN
string convert();

// EFFECTS return true if a has greater or equal precedence than b
bool precedence_greater(char a, char b);

// EFFECTS return the result of the rpn
int compute(string& rpn);

int main() {
    Dlist<char> charlist;
    Stack_t<char> charstack{charlist};
    try {
        string rpn = convert();
        cout << rpn << endl;
        cout << compute(rpn) << endl;
    } catch (parenthesis_mismatch e) {
        cout << "ERROR: Parenthesis mismatch" << endl;
    } catch (not_enough_operands e) {
        cout << "ERROR: Not enough operands" << endl;
    } catch (divide_by_zero e) {
        cout << "ERROR: Divide by zero" << endl;
    } catch (too_many_operands e) {
        cout << "ERROR: Too many operands" << endl;
    }
    return 0;
}

// convert infix to RPN
string convert() {
    string input;
    getline(cin, input);
    istringstream istream;
    istream.str(input);
    string token;
    string output;
    Dlist<char> operatorlist;
    Stack_t<char> operatorstack{operatorlist};
    while (istream >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!operatorstack.empty() && precedence_greater(operatorstack.top(), token[0]) && operatorstack.top() != '(') {
                output += operatorstack.top();
                output += " ";
                operatorstack.pop();
            }
            operatorstack.push(token[0]);
        } else if (token[0] == '(') {
            operatorstack.push('(');
        } else if (token[0] == ')') {
            try {
                while (operatorstack.top() != '(') {
                    output += operatorstack.top();
                    output += " ";
                    operatorstack.pop();
                }
            } catch (emptyList) {
                parenthesis_mismatch e;
                throw e;
            }
            if (operatorstack.top() == '(')
                operatorstack.pop();
        } else {
            output += token;
            output += " ";
        }
    }
    while (!operatorstack.empty()) {
        if (operatorstack.top() == '+' || operatorstack.top() == '-' || operatorstack.top() == '*' || operatorstack.top() == '/') {
            output += operatorstack.top();
            output += " ";
            operatorstack.pop();
        } else {
            operatorstack.pop();
            parenthesis_mismatch e;
            throw e;
        }
    }
    output.erase(output.find_last_not_of(' ') + 1);
    return output;
}

// return 1 if a >= b
bool precedence_greater(char a, char b) {
    if (a == '*' || a == '/')
        return true;
    else if (b == '+' || b == '-')
        return (b == '+' || b == '-');
    return false;
}

// return the result of the rpn
int compute(string& rpn) {
    istringstream istream;
    istream.str(rpn);
    Dlist<int> operantlist;
    Stack_t<int> operantstack{operantlist};
    string token;
    while (istream >> token) {
        try {
            if (token == "+") {
                int a = operantstack.top();
                operantstack.pop();
                int b = operantstack.top();
                operantstack.pop();
                operantstack.push(a + b);
            } else if (token == "-") {
                int a = operantstack.top();
                operantstack.pop();
                int b = operantstack.top();
                operantstack.pop();
                operantstack.push(b - a);
            } else if (token == "*") {
                int a = operantstack.top();
                operantstack.pop();
                int b = operantstack.top();
                operantstack.pop();
                operantstack.push(a * b);
            } else if (token == "/") {
                int a = operantstack.top();
                operantstack.pop();
                int b = operantstack.top();
                operantstack.pop();
                if (a == 0) {
                    divide_by_zero error;
                    throw error;
                }
                operantstack.push(b / a);
            } else {
                operantstack.push(stoi(token));
            }
        } catch (emptyList e) {
            not_enough_operands error;
            throw error;
        }
    }
    if (operantstack.empty()) {
        not_enough_operands e;
        throw e;
    }
    int result = operantstack.top();
    operantstack.pop();
    if (operantstack.empty())
        return result;
    else {
        too_many_operands error;
        throw error;
    }
}