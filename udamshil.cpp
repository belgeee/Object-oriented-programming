#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    float length;
    float area;

public:
    float getLength() { return length; }
    float getArea() { return area; }

    Shape(float a) {
        length = a;
        area = 0; // Initialize area to 0, as it's not set in the constructor.
    }

    Shape() {
        length = 0;
        area = 0;
    }
};

class TwoDShape : public Shape {
protected:
    float perimeter;

public:
    float getPerimeter() { return perimeter; }
};

class Circle : public TwoDShape {
public:
    Circle(float a) {
        length = a;  // Manually set length
        perimeter = 2 * M_PI * length;
        area = M_PI * length * length;
    }
};

class Square : public TwoDShape {
public:
    Square(float a){
        length = a;  // Manually set length
        perimeter = 4 * length;
        area = length * length;
    }
};

class Triangle : public TwoDShape {
public:
    Triangle(float a) {
        length = a;  // Manually set length
        perimeter = 3 * length;
        area = 0.433 * length * length / 2; // Correct area formula for equilateral triangle.
    }
};

int main() {
    Circle c(3);
    cout << "Circle: " << c.getLength() << ' ' << c.getPerimeter() << ' ' << c.getArea() << endl;

    Square sq(2);
    cout << "Square: " << sq.getLength() << ' ' << sq.getPerimeter() << ' ' << sq.getArea() << endl;

    Triangle tria(2);
    cout << "Triangle: " << tria.getLength() << ' ' << tria.getPerimeter() << ' ' << tria.getArea() << endl;

    return 0;
}
