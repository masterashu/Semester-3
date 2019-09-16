#include <iostream>
using namespace std;

// Standard Class
class Hello {
   private:
    int num;
    double rate;

   public:
    // Constructor
    Hello(){
        this->num = 0;
        this->rate = 0;
    }
    Hello(int num, double rate){
        this->num = num;
        this->rate = rate;
    }
    // Getters
    double Rate() {
        return this->rate;
    }

    int Num() {
        return this->Num;
    }

    // Setters
    void Rate(double rate) {
        this->rate = rate;
    }

    void Num(int Num) {
        this->Num = Num;
    }
};

// Read Only Class
class HelloReadOnly {
   private:
    int num;
    double rate;

   public:
    // Constructor
    HelloReadOnly(){
        this->num = 0;
        this->rate = 0;
    }

    HelloReadOnly(int num, double rate){
        this->num = num;
        this->rate = rate;
    }
    // Getters
    double Rate() {
        return this->rate;
    }

    int Num() {
        return this->Num;
    }
};

