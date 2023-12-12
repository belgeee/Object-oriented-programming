#include <iostream>
using namespace std;
class shape
{
protected:
    float *x;
    float *y;
    float a;
    float s;
    float p;

public:
    static int number;
    static void show_number();
    virtual ~shape()
    {
        number--;
    }
    shape(float a) {
        number++; 
    }

    shape() {
        number++;
    }
    virtual float get_s(){
        return this->s;
    }
    virtual float get_p(){
        return this->p;
    }
};
void shape::show_number()
{
    cout << "Object:" << number << endl;
}
int shape ::number = 0;


class twoD : public shape
{
protected:
    float p;

public:
    twoD(float a, int points);
    virtual float area() = 0;
    virtual float perimetr() = 0;
    float get_s();
    float get_p();
};
twoD::twoD(float a, int points)
{
    this->a = a;
    this->x = new float[points];
    this->y = new float[points];
}
float twoD::get_s()
{
    return this->s;
}
float twoD::get_p()
{
    return this->p;
}



class circle : public twoD
{
public:
    circle(float r);
    float area();
    float perimetr();
};
circle::circle(float r) : twoD(r, 1)
{
    cout << " Circle constucter: s = " << this->area() << endl
         << "Circle perimetr: p = " << this->perimetr() << endl;
}
float circle::area()
{
    this->s = 3.14 * this->a * this->a;
    return this->s;
}
float circle::perimetr()
{
    this->p = 2 * 3.14 * this->a;
    return this->p;
}



class square : public twoD
{
public:
    square(float a);
    float area();
    float perimetr();
};
square::square(float a) : twoD(a, 4)
{
    cout << " square constucter: s =" << this->area() << endl
         << "Square perimetr: p = " << this->perimetr() << endl;
}
float square::area()
{
    this->s = this->a * this->a;
    return this->s;
}
float square::perimetr()
{
    this->p = 4 * this->a;
    return this->p;
}



class triangle : public twoD
{
public:
    triangle(float a);
    float area();
    float perimetr();
};
triangle::triangle(float a) : twoD(a, 3)
{
    cout << " triangle constucter: s= " << this->area() << endl
         << "Triangle perimetr: p = " << this->perimetr() << endl;
}
float triangle::area()
{
    this->s = 0.5 * this->a * this->a * 0.866;
    return this->s;
}
float triangle::perimetr()
{
    this->p = 3 * this->a;
    return this->p;
}
int main()
{
    circle c1(5), c2(2);
    square s1(5), s2(3);
    triangle t1(5), t2(2);
    shape::show_number();

    twoD *shapes[7];
    shapes[0] = &c1;
    shapes[1] = &c2;
    shapes[2] = &s1;
    shapes[3] = &s2;
    shapes[4] = &t1;
    shapes[5] = &t2;
    shapes[6]=NULL;
    for (int i = 0; i < 6; i++)
    {

        cout << "S= " << shapes[i]->get_s() << endl;

        cout << "P= " << shapes[i]->get_p() << endl;
    }
    cout << "sort by Area" << endl;

    for (int i = 0; i < 6; i++)
    {

        for (int j = 0; j < 6-i; j++)
        {
            if (shapes[j]->get_s() > shapes[j + 1]->get_s())
            {
                shapes[6] = shapes[j + 1];
                shapes[j + 1] = shapes[j];
                shapes[j] = shapes[6];
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << shapes[i]->get_s() << endl;
    }
    cout << "gonna sort by Perimeter" << endl;
    for (int i = 0; i < 6; i++)
    {

        for (int j = 0; j < 6-i ; j++)
        {
            if (shapes[j + 1]->get_p() > shapes[j]->get_p())
            {
                shapes[6] = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = shapes[6];
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {

        cout << shapes[i]->get_p() << endl;
    }


}
