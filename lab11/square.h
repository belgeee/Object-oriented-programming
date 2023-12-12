#include "2d.h"                     //2d.h header file холбож байна
#ifndef __square__
#define __square__


class square:public twod{  
   public:                          //2dshape классаас удамшина
      float area();                 //талбай олох функц
      float perimeter();            //периметр олох функц
      void coordinate();            //
      square(float a, float x1,float y1);           //координатын цэгүүдийг олох функц
      ~square();
};
#endif 