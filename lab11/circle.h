#include "2d.h"                  
#ifndef __circle__
#define __circle__


class circle:public twod{        
public:
   float area();                 
   float perimeter();            
   void coordinate();            
   circle(float a, float x1, float y1);
   ~circle();
};
#endif 