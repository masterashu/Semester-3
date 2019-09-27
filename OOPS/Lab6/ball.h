#include <iostream>

class Ball {
   private:
    double x;
    double y;
    double xSpeed;
    double ySpeed;

   public:
    // Constructors
    Ball();
    Ball(double x, double y, double xSpeed, double ySpeed);
    // Getters and Setters
    double getX();
    void setX(double x);
    double getY();
    void setY(double y);
    double getXSpeed();
    void setXSpeed(double xSpeed);
    double getYSpeed();
    void setYSpeed(double ySpeed);
    void setXY(double x, double y);
    void setXYSpeed(double xSpeed, double ySpeed);
    void move();
    void print();
};
