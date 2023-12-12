#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() const {
        cout << "Some generic animal sound" << endl;
    }

    virtual ~Animal() {}  
};
class Dog : public Animal {
public:
    void makeSound()  {  
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() { 
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    myDog->makeSound();  // Outputs: Woof!
    myCat->makeSound();  // Outputs: Meow!

    delete myDog;
    delete myCat;

    return 0;
}
