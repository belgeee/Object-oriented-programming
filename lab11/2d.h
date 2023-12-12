#include "shape.h"                          
#ifndef __2d__
#define __2d__
#include<string.h>
#include <iostream>
using namespace std; 

class twod: public shape{                   
    friend ostream & operator<<(ostream &out, const twod &c);
    public:   
        float area1;
        int perimeter1;                              
        virtual float area()=0;           
        virtual float perimeter()=0; 
        float *x;                           
        float *y;                           
        void show_data(void);               
        virtual void coordinate()=0;        
        bool operator<(twod &b);
        bool operator>(twod &b);
        twod(float a, int point);           
        ~twod();                            
};
#endif 