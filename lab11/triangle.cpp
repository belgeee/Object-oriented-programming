#include "triangle.h"               //triangle.h header file холбож байна
#include <math.h>
#include<iostream>

using namespace std;
float triangle::perimeter(){        //периметр функц тодорхойлолт
    this->perimeter1=3*a;
    return perimeter1;                     //периметрийг олон буцааж байна
}
float triangle::area(){             //талбай олох функцийн тодорхойлолт
    float h=sqrt(a*a-a/2*a/2);      //гурвалжны өндөрийг олж байна
    this->area1=a*h/2;
    return area1;                   //талбайг олон буцааж байна
}
void triangle::coordinate(){        //координатын цэгийг олох функц тодорхойлолт
    float h=sqrt(a*a-a/2*a/2);
    x[1]=x[0]+a/2;          //х у цэгүүдийг олж байна
    y[1]=y[0]-h;
    x[2]=x[0]-a/2;
    y[2]=y[0]-h;
}
triangle::triangle(float a, float x1, float y1):twod(a,3){
        name=new char[9];
        strcpy(name,"triangle");
        this->area();
        this->perimeter();
        this->x[0]=x1;
        this->y[0]=y1;
        coordinate();
}
triangle::~triangle(){
    delete[] name;
}