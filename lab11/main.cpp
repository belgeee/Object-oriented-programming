#include <iostream>
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "./LinkedListelement.cpp"
using namespace std;


int main() {
    srand(time(0));

    int n = 10;
    LinkedListelement<twod*> element;

    for (int type = 0; type < 3; ++type) {
        for (int i = 0; i < n; ++i) {
            twod* shape = nullptr;

            switch (type) {
                case 0:
                    shape = new circle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
                    break;
                case 1:
                    shape = new square(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
                    break;
                case 2:
                    shape = new triangle(rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
                    break;
            }

            element.add(shape);
        }
    }

    cout << "Unsorted:" << endl;
    element.display();

    cout << "\nSorted:" << endl;
    element.sort();
    element.display();

    return 0;
}