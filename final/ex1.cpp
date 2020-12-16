//
// Created by 朱星宇 on 2020/8/4.
#include <vector>
#include <deque>
#include <list>
using namespace std;
class foo{
    int a,b;

public:
    foo(int _a, int _b=0);
    void set(int _a=0, int _b=0);
};

class bar: public foo{
public:
    bar();
    void set(int _a=1, int _b=1);
};

int main(){
    foo* pa = new bar;
    bar* pb = dynamic_cast<bar*>(pa);
    return 0;
}