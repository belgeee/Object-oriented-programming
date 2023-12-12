#include "2d.h"                  //2d.h header file холбож байна
#ifndef __triangle__
#define __triangle__


class triangle:public twod{        //2dshape классаас удамшина
public:
   float area();                 //талбай олох функц
   float perimeter();            //периметр олох функц
   void coordinate();            //координатын цэгүүдийг олох функц
   triangle(float a, float x1, float y1);
   ~triangle();
};
#endif 