#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Complex
{
    private:
        float a, b;

    public:
        Complex(){
            a = 0;
            b = 0;
        }
        Complex(float x) {
            a = x;
            b = x;
        }
        Complex(float x, float y){
            a = x;
            b = y;
        }
        void showComplex(){
            cout << "Complexlex Number is: " << a << " + " << b << "i " << ".\n";
        }
        float get_real(){
            return a;
        }
        float get_imaginary(){
            return b;
        }
        void setValues(float x, float y){
            a = x;
            b = y;
        }
        void add(Complex complex1, Complex complex2){
            a = complex1.get_real() + complex2.get_real();
            b = complex1.get_imaginary() + complex2.get_imaginary();
        }
};
int main()
{
    float x1,y1;
    // No parameter Constructor
    cout << "// No parameter Constructor" << endl;
    Complex complex1;
    complex1.showComplex();
    
    // One parameter Constructor
    cout << "// One parameter Constructor" << endl;
    cin >> x1;
    Complex complex2(x1);
    complex2.showComplex();

    // Two parameter Constructor
    cout << "// Two parameter Constructor 1" << endl;
    cin >> x1 >> y1;
    Complex complex3(x1, y1);
    complex3.showComplex();

    cout << "// Two parameter Constructor 2" << endl;
    cin >> x1 >> y1;
    Complex complex4(x1, y1);
    complex4.showComplex();
    
    cout << "// Addition Function" << endl;
    Complex complex5;
    complex5.add(complex3, complex4);
    complex5.showComplex();
    
    return 0;
}
