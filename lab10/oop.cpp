#include <iostream>

using namespace std;



class shape
{
protected:
    float length;
    float area;

public:
    float getArea()
    {
        return area;
    }
    float getLength()
    {
        return length;
    }
};

class twod : public shape
{
protected:
    float perimeter;

public:
    virtual float getPerimeter()
    {
        return perimeter;
    }
};

class Circle : public twod
{
public:
    Circle(float a)
    {
        length = a;                               
        perimeter = 2 * M_PI * (length / 2);      
        area = M_PI * (length / 2) * (length / 2); 
    }
};

class Square : public twod
{
public:
    Square(float a)
    {
        length = a; 
        perimeter = 4 * length;
        area = length * length;
    }
};

class Triangle : public twod
{
public:
    Triangle(float a)
    {
        length = a;
        perimeter = 3 * length;
        area = sqrt(3) / 4 * length * length;
    }
};

int main()
{
    Circle c(3);
    Square sq(2);
    Triangle tria(2);

    twod *shapes[3] = {&c, &sq, &tria};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2 - i; ++j)
        {
            if (shapes[j]->getArea() > shapes[j + 1]->getArea())
            {
                twod *temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }

    cout << "Shapes sorted by area:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Length: " << shapes[i]->getLength()
             << ", Perimeter: " << shapes[i]->getPerimeter()
             << ", Area: " << shapes[i]->getArea() << endl;
    }
    return 0;
}