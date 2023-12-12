#include <iostream>
using namespace std;
template <class T>
class element {
public:
    T _t;
    element<T>* next = nullptr;
};

template <class T>
class LinkedListelement {
public:
    element<T>* head = nullptr;
    element<T>* tail = nullptr;
    int len = 0;

    ~LinkedListelement() {
        while (head != nullptr) {
            element<T>* nd = head->next;
            delete head;
            head = nd;
        }
        len = 0;
    }

    void add(T t) {
        if (len == 0) {
            len = 1;
            element<T>* nd = new element<T>;
            nd->_t = t;
            head = nd;
            tail = nd;
        } else {
            len++;
            element<T>* nd = new element<T>;
            nd->_t = t;
            tail->next = nd;
            tail = tail->next;
        }
    }

    void insert(T t, int index) {
        if (index > len) {
            cout << "error" << endl;
            exit(0);
        } else {
            element<T>* nd = new element<T>;
            nd->_t = t;
            element<T>* p = head;
            for (int a = 0; a < index - 1; a++) {
                p = p->next;
            }
            element<T>* q = p->next;
            p->next = nd;
            nd->next = q;
            len++;
        }
    }

    T get(int index) {
        if (index < len) {
            element<T>* p = head;
            for (int a = 0; a < index; a++) {
                p = p->next;
            }
            return p->_t;
        } else {
            exit(0);
        }
    }

    void del(int index) {
        if (index < len) {
            element<T>* p = head;
            for (int a = 0; a < index - 1; a++) {
                p = p->next;
            }
            element<T>* q = p->next->next;
            delete p->next;
            p->next = q;
            len--;
        }
    }

    int length() {
        return len;
    }

    void display() {
        element<T>* nd = head;
        for (int i = 0; i < len; i++) {
            cout << "Area: " << nd->_t->area() << endl;
            nd = nd->next;
        }
    }

    void sort() {
        element<T>* first;
        element<T>* second;
        for (int i = 0; i < len - 1; i++) {
            element<T>* nd = head;
            for (int j = 0; j < len - 1 - i; j++) {
                first = nd;
                second = nd->next;
                if (first->_t->area() > second->_t->area()) {
                    T tmp = first->_t;
                    first->_t = second->_t;
                    second->_t = tmp;
                }
                nd = nd->next;
            }
        }
    }
};