#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
    private:
        float width, length;                
        class Centroid {
            private:
                float x, y;
            public:
                Centroid(float X, float Y){
                    x = X;
                    y = Y;
                }
                void show(){
                    cout << x << ',' << y << endl;
                }
        };

    public:
        Rectangle (float l, float w){
            width = w;
            length = l;
        }
        void setLength(float l){
            length = l;
        }
        void setWidth(float w){
            width = w;
        }
        float perimeter(){
            return (length + width) * 2;
        }
        float area(){
            return length * width;
        }
        void show(){
            cout << "Length is: " << length << ", Width is: " << width << endl;
            cout << "Diameter of Rect is: " << calcDiag() << endl;
            cout << "Area of Rect is: " << area() << endl;
            cout << "Perimeter of Rect is: " << perimeter() << endl;
            Centroid *tmp = centroid();
            cout << "Value of centroid is ";
            tmp->show();
        }
        int sameArea(Rectangle rect){
            if (area() == rect.area()){
                return 1;
            }
            return 0;
        }
        float calcDiag(){
            return sqrt(length * length + width * width);
        }
        Centroid* centroid(){
            return new Centroid(length/2, width/2);
        }

};


int main(int argc, char const *argv[])
{
    float length, width;
    cout << "\nEnter Length and Width of Rectangle: ";
    cin >> length >> width;
    Rectangle rect1(length, width);
    cout << "Rectangle 1: \n";
    rect1.show();
    cout << "Rectangle 2: \n";
    cout << "\nEnter Length and Width of Rectangle: ";
    cin >> length >> width;
    Rectangle rect2(length, width);
    rect2.show();
    cout << endl;
    if(rect1.sameArea(rect2)){
        cout << "Rectangles have the Same Area\n";
    }
    else {
        cout << "Rectangles does not have the Same Area\n";
    }
    return 0;
}
