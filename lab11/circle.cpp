#include "circle.h"             
#include <math.h>               
#include<iostream>

using namespace std;
float circle::perimeter(){      
    this->perimeter1=2*3.14*a;
    return perimeter1;            
}
float circle::area(){           
        this->area1=3.14*a*a;
        return area1;        
    }
void circle::coordinate(){

}
circle::circle(float a, float x1, float y1):twod(a,1){  
    name=new char[7];
    strcpy(name,"circle");
    this->area();
    this->perimeter();
        this->x[0]=x1;           
        this->y[0]=y1;           
}
circle::~circle(){
    delete[] name;
}