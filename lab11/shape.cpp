#include "shape.h"
#include<string.h>
#include<iostream>

using namespace std;
shape::shape(float a){      //байгуулагч функц тодорхойлолт
    this->a=a;              //a хувьсагчид параметрээр орж ирсэн утгыг онооно
    //number++;               //статик хувьсагчийг нэмэгдүүлж байна.
}
// int shape::number=0;        //статик хувьсагчид гарааны утга оноож байна.

// /*void shape::number_ret(){                            //статик функц тодорхойлолт
//     cout<<"number: "<<number<<endl;                 //статик гишүүн өгөгдлийг хэвлэж харуулж байна
// }*/