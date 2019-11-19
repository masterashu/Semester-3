#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class A{
    private:
    int a1;
    public:
    A(){
        a1 = 10, a2 = 29;
    }
    int a2;
    int get_a1(){
        return a1;
    }
    void display(){
        cout << a1 << ":" << a2 << endl;
    }
};

class B: public A{
    private:
    int c;
    public:
    B():A(){
        c = 12;
    }
    void display1(){
        cout << get_a1() << ":" << a2 << ":" << c << endl;
    }
};

int main(int argc, char const *argv[]) {
    B abc;
    abc.display1();
    abc.display();
    return 0;
}