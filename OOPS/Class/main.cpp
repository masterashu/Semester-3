#include <iostream>
#include <thread>
#include <bits/stl_threads.h>

using namespace std;

class FP1 {
   public:
    void operator()(int x, string str) {
        for (int i = 0; i < x; i++) {
            cout << "Thread 1 printing " << str;
        }
    }
};

void SP1(int x, string str) {
    for (int i = 0; i < x; i++) {
        cout << "Thread 2 printing " << str;
    }
}

int main(int argc, char const *argv[]) {
    std::thread thread1(FP1(), 10, "Hello World!\n");
    std::thread thread2(SP1, 10, "Another Thread running!\n");
    // thread1.join();
    thread2.join();
    return 0;
}
