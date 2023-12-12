#include <iostream>

using namespace std;

class Base {
public:
    virtual void print() {  
        cout << "Print base class" << endl;
    }
};

class Derived : public Base {
public:
    void print() {  
        cout << "Print derived class" << endl;
    }
};

int main() {
    Base *base_ptr;
    Derived d;
    base_ptr = &d;

    base_ptr->print(); 
    return 0;
}