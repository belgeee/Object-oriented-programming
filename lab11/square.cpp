#include <iostream>
using namespace std;
#include "square.h"                 //square.h header file холбож байна
    float square::perimeter(){      //периметр функц тодорхойлолт
        this->perimeter1=4*a;
        return perimeter1;                 //периметрийг олон буцааж байна
    }
    float square::area(){           //талбай олох функцийн тодорхойлолт
        this->area1=a*a;
        return area1;                 //талбайг олон буцааж байна
    }
    void square::coordinate(){      //координатын цэгүүдийг олох функц тодорхойлолт
        x[1]=x[0]+a;                //х у цэгүүдийг олж байна
        y[1]=y[0];
        x[2]=x[0]+a;
        y[2]=y[0]-a;
        x[3]=x[0];
        y[3]=y[0]-a;
    }
    square::square(float a, float x1, float y1):twod(a, 4){//удамшсан байгуулагч функцийн тодорхойлолт, эх класс руу а,4 дамжуулна
        name=new char[7];                                   //нэр хаяган хувьсагчид 7 хэмжээтэй санах ой нөөцөлж байна
        strcpy(name,"square");                              //square гэсэн үгийг нөөцөлсөн санах ой руу хуулж өгч байна
        this->area();
        this->perimeter();
        this->x[0]=x1;
        this->y[0]=y1;
        coordinate();
        area();
    }
    square::~square(){
        delete[] name;
    }