import java.util.Scanner;
import java.lang.*;

class Rectangle {
    float width, length;                
    class Centroid {
        float x, y;
        Centroid(float X, float Y){
            this.x = X;
            this.y = Y;
        }
        void show(){
            System.out.print(this.x + ',' + this.y + '\n');
        }
    };

    Rectangle (float l, float w){
        this.width = w;
        this.length = l;
    }
    void setLength(float l){
        this.length = l;
    }
    void setWidth(float w){
        this.width = w;
    }
    float perimeter(){
        return (this.length + this.width) * 2;
    }
    float area(){
        return this.length * this.width;
    }
    void show(){
        System.out.print("Length is: " + this.length + ", Width is: " + width + '\n');
        System.out.print("Diameter of Rect is: " + this.calcDiag() + '\n');
        System.out.print("Area of Rect is: " + this.area() + '\n');
        System.out.print("Perimeter of Rect is: " + this.perimeter() + '\n');
        Centroid tmp = this.centroid();
        System.out.print("Value of centroid is ");
        tmp.show();
    }
    boolean sameArea(Rectangle rect){
        if (this.area() == rect.area()){
            return true;
        }
        return false;
    }
    double calcDiag(){
        return Math.sqrt(this.length * this.length + this.width * this.width);
    }
    Centroid centroid(){
        return new Centroid(this.length/2, this.width/2);
    }

};

class lab4{

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in); 
        float length, width;
        System.out.print("Enter Length and Width of Rectangle: ");
        length = sc.nextInt();
        width = sc.nextInt();
        Rectangle rect1 = new Rectangle(length, width);
        System.out.print("Enter Length and Width of Rectangle: ");
        length = sc.nextInt();
        width = sc.nextInt();
        Rectangle rect2 = new Rectangle(length, width);
        rect1.show();
        System.out.print("Diameter of Rect1 is: " + rect1.calcDiag() + "\n");
        System.out.print("Area of Rect1 is: " + rect1.area() + "\n");
        System.out.print("Perimeter of Rect1 is: " + rect1.perimeter() + "\n");
        rect2.show();
        System.out.print("Diameter of Rect2 is: " + rect2.calcDiag() + "\n");
        System.out.print("Area of Rect2 is: " + rect2.area() + "\n");
        System.out.print("Perimeter of Rect2 is: " + rect2.perimeter() + "\n");

        if(rect1.sameArea(rect2)){
            System.out.print("Rectangles have the Same Area\n");
        }
        else {
            System.out.print("Rectangles does not have the Same Area\n");
        }
    }
}