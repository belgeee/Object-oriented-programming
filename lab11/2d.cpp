#include "2d.h"
#include <iostream>
#include<string.h>

using namespace std;
void twod::show_data(void){ 
            cout<<"-------------"<<endl;
            cout<<name<<endl;
            cout<<"side: ";
            cout<<a<<endl;
            cout<<"area: ";
            cout<< area1<<endl;
            cout<<"perimeter: ";
            cout<< perimeter1<<endl;
            cout<<endl;
        }

bool twod::operator<(twod &b){
    if(this->area1 < b.area1){
        return true;
    }
    return false;
}
bool twod::operator>(twod &b){
    if(this->area1 > b.area1){
        return true;
    }
    return false;
}
ostream & operator<<(ostream &out, const twod &c){
    out << "--------------------\n";
    out << "shape:    " << c.name << "\n";
    out << "area:     " << c.area1 << "\n";
    out << "perimetr: " << c.perimeter1 << endl;
    return out;
}
twod::twod(float a, int point):shape(a){            
    this->a = a;                                    
    this->x = new float[point];                     
    this->y = new float[point];                     
}
twod::~twod(){
    delete[] x;                                     
    delete[] y;                                     
}  