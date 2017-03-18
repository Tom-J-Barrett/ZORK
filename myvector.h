#ifndef MYVECTOR_H
#define MYVECTOR_H

template<class T>
class myVector
{
    int vsize,maxsize;
    T* array;
    void alloc_new();
public:
    myVector();
    myVector(int);
    myVector(const myVector&);
    ~myVector();
    void push_back(const T&);
    void pop();
    int size();
    T operator[](int);
    myVector& operator=(const myVector&);
    myVector& operator+=(const T&);
    int at(T&);
private:

};

#endif // MYVECTOR_H
