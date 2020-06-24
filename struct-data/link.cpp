#include<iostream>

using namespace std;

class IntElement {
public:
    IntElement(int value):next(NULL), data(value) {}
    ~IntElement(){}

    IntElement* getNext() const { return next; }
    int getValue() const { return data; }
    void setNext(IntElement* elem) { next = elem; }
    void setValue(int value) { data = value; }

private:
    IntElement* next;
    int data;
};

//<>括号中的参数叫模板形参，模板形参和函数形参很相像，
// 模板形参不能为空。一但声明了模板函数就可以用模板函数的形参名声明类中的成员变量和成员函数，
// 即可以在该函数中使用内置类型的地方都可以使用模板形参名。
template <class T>
class ListElement {
public:
    ListElement(const T &value): next(NULL), data(value){}
    ~ListElement(){}

    ListElement* getNext() const { return next; }
    const T& value() const { return data; }
    void setNext(ListElement* elem) { next = elem; }
    void setValue(const T& value) { data = value; }

private:   
    ListElement* next;
    int data;
}