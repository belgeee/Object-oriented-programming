#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
template <typename T> class List{
    private:
        vector<T> list;
    public:
        void add(T t);
        void insert (T t, int index);
        T get(int index);
        void remove(int index);
        int length();
};
template <typename T> void List<T>::add(T t){
list.push_back(t);

}
template <typename T> void List<T>::insert(T t, int index){
if (index >= 0 && index <= list.size()) {
        list.insert(list.begin() + index, t);
    }
}
template <typename T> T List<T>::get(int index){
  if (index >= 0 && index < list.size()) {
        return list[index];
    }  
}
template <typename T> void List<T>::remove(int index){
    if (index >= 0 && index < list.size()) {
        list.erase(list.begin() + index);
    }
}
template <typename T> int List<T>::length(){
    return list.size();
}





class Shape {
protected:
    string name;
    static int count;

public:
    Shape() {count++;}
    Shape(string name) {
        this->name = name;
    }
    string getname() {
        return name;
    }
    ~Shape(){
        cout<<"destructor"<<endl;
    }
    static int getcount(){
        return count;
    }
     virtual float talbai(){
        return 0;
    };
    virtual float peri(){
        return 0;
    }; 
    virtual void getinfo(){
         cout << "Shape: " << name << endl;
        cout << "Area: " << talbai() << endl;
        cout << "Perimeter: " << peri() << endl;
    }
};
int Shape::count=0;

class twoDShape : public Shape {
protected:
    float x, y;
    float a;
    static float pi;

public:
    twoDShape(string b, float a, float c);
    ~twoDShape();
    

};

float twoDShape::pi = 3.14;

twoDShape::twoDShape(string b, float a, float c) {
   this->name = b;
    this->a = a;
    this->x = rand() % 100;  
    this->y = rand() % 100;
}

twoDShape::~twoDShape() {}

class Round : public twoDShape {
public:
    Round(float r);
    float talbai() override;
    float urt();
    float peri();
    void getinfo() override;
};
void Round::getinfo(){
        cout << " Radius: " << a << endl;
        cout << "Area: " << talbai() << endl;
        cout << "Perimeter: " << peri() << endl;
}

Round::Round(float r) : twoDShape("Circle", r, 1) {
    cout << "Ner:" << this->name << endl;
    cout << "Radius urt: " << a << endl;
    cout << "talbai: " << talbai() << endl;
    cout << "urt: " << urt() << endl;
    cout << "x: " << this->x << " y: " << this->y << endl<<endl;
}

float Round::talbai() {
    return pi * this->a * this->a;
}

float Round::urt() {
    return 2 * pi * this->a;
}
float Round::peri(){
    return 2*this->a;
}

class square : public twoDShape {
public:
    square(float a);
    float talbai() override;
    float peri() override;
    void cal();
    void getinfo() override;
};

square::square(float a) : twoDShape("Square", a, 4) {
    cout << "Ner:" << this->name << endl;
    cout << "taliin urt: " << a << endl;
    cout << "talbai: " << talbai() << endl;
    cout << "perimeter: " << peri() << endl<<endl;
    cal();
}
void square::getinfo(){
        cout << " Side Length: " << a << endl;
        cout << "Area: " << talbai() << endl;
        cout << "Perimeter: " << peri() << endl;    
}

float square::talbai() {
    return this->a * this->a;
}

float square::peri() {
    return 2 * this->a;
}

void square::cal() {
    cout << "Square Coordinates:" << endl;
    float x1 = this->x;
    float y1 = this->y;
    float x2 = x1 + this->a;
    float y2 = y1;
    float x3 = x1;
    float y3 = y1 + this->a;
    float x4 = x2;
    float y4 = y3;

    cout << "Point 1: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Point 2: (" << x2 << ", " << y2 << ")" << endl;
    cout << "Point 3: (" << x3 << ", " << y3 << ")" << endl;
    cout << "Point 4: (" << x4 << ", " << y4 << ")" << endl;
}

class triangle : public twoDShape {
public:
    triangle(float a);
    float talbai() override;
    float peri() override;
    void cal();
    void getinfo() override;
};
void triangle::getinfo(){

        cout << " Side Lenght: " << a << endl;
        cout << "Area: " << talbai() << endl;
        cout << "Perimeter: " << peri() << endl;
    
}

triangle::triangle(float a) : twoDShape("Triangle", a, 3) {
    cout << "Ner:" << this->name << endl;
    cout << "taliin urt: " << a << endl;
    cout << "talbai: " << talbai() << endl;
    cout << "perimeter: " << peri() << endl<<endl;
    cal();
}

float triangle::talbai() {
    return (this->a * this->a) / 2;
}

float triangle::peri() {
    return 3 * this->a;
}

void triangle::cal() {
    cout << "Triangle Coordinates:" << endl;
    float x1 = this->x;
    float y1 = this->y;
    float x2 = x1 + (this->a / 2);
    float y2 = y1;
    float x3 = x1;
    float y3 = y1 + this->a;

    cout << "Point 1: (" << x1 << ", " << y1 << ")" << endl;
    cout << "Point 2: (" << x2 << ", " << y2 << ")" << endl;
    cout << "Point 3: (" << x3 << ", " << y3 << ")" << endl;
}

int main() {
    
    List<twoDShape*> shapeList;
    
    for(int i=0; i < 10;i++){
        int n=rand()%100;
        Round* c = new Round(n);
        shapeList.add(c);
    }
    
    for (int i = 0; i < 10; i++)
    {
         int n=rand()%100;
      square* q = new square(n);
        shapeList.add(q);
    }
    
     for (int i = 0; i < 10; i++)
    {
         int n=rand()%100;
      triangle* t = new triangle(n);
        shapeList.add(t);
    }
   twoDShape* shapes[shapeList.length()];

    for (int i = 0; i < shapeList.length(); i++) {
        shapes[i] = shapeList.get(i);
        cout <<endl<< "index " << i + 1 << ": ";
        cout<<shapes[i]->getname();
        shapes[i]->getinfo();
        cout << endl;
        
    }
    for (int step = 0; step < shapeList.length(); ++step) {
        for (int i = 0; i < shapeList.length() - step; ++i) {
            if (i < shapeList.length()-1 && shapes[i]->talbai() > shapes[i + 1]->talbai()) {
                swap(shapes[i], shapes[i + 1]);
            }
        }
    }
   
    cout << "Sorted shapes by area:" << endl;
    for (int i = 0; i < shapeList.length(); ++i) {
        cout <<"Index:"<< i+1<<"  "<<shapes[i]->getname() << " Area: " << shapes[i]->talbai() << endl;
    }

      for (int step = 0; step < shapeList.length(); ++step) {
        for (int i = 0; i < shapeList.length() - step; ++i) {
            if (i < shapeList.length()-1 && shapes[i]->peri() > shapes[i + 1]->peri()) {
                swap(shapes[i], shapes[i + 1]);
            }
        }
    }
    
    cout <<endl<< "Sorted shapes by perimetr:" << endl;
    for (int i = 0; i < shapeList.length(); ++i) {
        cout << "Index:"<<i+1<<"  "<<shapes[i]->getname() << " Perimetr: " << shapes[i]->peri() << endl;
    }
    triangle* extra = new triangle(200);
    shapeList.insert(extra, 10);
    cout<< "Total objects:"<<Shape::getcount()<<endl;
    

    for (int i = 0; i < shapeList.length(); i++) {
        shapeList.remove(i);
    }
    

    

return 0;
}
