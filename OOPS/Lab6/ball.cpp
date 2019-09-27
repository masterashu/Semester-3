#include <iostream>
#include <iomanip>
#include "ball.h"
using namespace std;

Ball::Ball() {
    this->x = 0;
    this->y = 0;
    this->xSpeed = 0;
    this->ySpeed = 0;
}

Ball::Ball(double x, double y, double xSpeed, double ySpeed) {
    this->x = x;
    this->y = y;
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
}

double Ball::getYSpeed() {
    return this->ySpeed;
}
void Ball::setYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

double Ball::getXSpeed() {
    return this->xSpeed;
}

void Ball::setXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

double Ball::getY() {
    return this->y;
}

void Ball::setY(double y) {
    this->y = y;
}

double Ball::getX() {
    return this->x;
}

void Ball::setX(double x) {
    this->x = x;
}

void Ball::setXY(double x, double y){
    this->x = x;
    this->y = y;
}
void Ball::setXYSpeed(double xSpeed, double ySpeed){
    this->xSpeed = xSpeed;
    this->ySpeed = ySpeed;
}

void Ball::move(){
    cout << "\nMoving Ball...";
    this->x += this->xSpeed;
    this->y += this->ySpeed;
}
void Ball::print(){
    cout << setprecision(2) << "\nBall @ (" << this->x << ',' << this->y << ") with speed ("  << this->xSpeed << ',' << this->ySpeed << ").";

}

int main(int argc, char const *argv[]) {
    // Constructor
    double x, y, xSpeed, ySpeed;
    cout << "\nEnter coordinates: ";
    cin >> x >> y;
    cout << "\nEnter speed: ";
    cin >> xSpeed >> ySpeed;

    Ball b1(x, y, xSpeed, ySpeed);

    b1.print();
    b1.move();
    b1.print();

    // Using Setters
    cout << "Enter coordinates: ";
    cin >> x >> y;
    cout << "Enter speed: ";
    cin >> xSpeed >> ySpeed;

    Ball b2;
    b2.setX(x);
    b2.setY(y);
    b2.setXSpeed(xSpeed);
    b2.setYSpeed(ySpeed);

    b2.print();
    b2.move();
    b2.print();

    // Using Methods
    cout << "\nEnter coordinates: ";
    cin >> x >> y;
    cout << "\nEnter speed: ";
    cin >> xSpeed >> ySpeed;

    Ball b3;
    b3.setXY(x, y);
    b3.setXYSpeed(xSpeed, ySpeed);

    b3.print();
    b3.move();
    b3.print();


    return 0;
}
