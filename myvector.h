#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;

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
    void pop_back();
    int size();
    T back();
    T operator[](int);
    myVector& operator=(const myVector&);
    myVector& operator+=(const T&);
    int at(T&);

};

template<class T>
myVector<T>::myVector(){
    maxsize=20;
    array=new T[maxsize];
    vsize=0;
}

template<class T>
myVector<T>::myVector(int i){
    maxsize=i;
    array= new T[maxsize];
    vsize=0;
}

template<class T>
myVector<T>::myVector(const myVector & v){
    maxsize=v.maxsize;
    vsize=v.vsize;
    array=new T[maxsize];
    for(int i=0;i<v.vsize;i++)
        array[i]=v.array[i];
}

template<class T>
myVector<T>::~myVector(){
    delete [] array;
}

template<class T>
void myVector<T>::push_back(const T& i){
    if(vsize+1>maxsize)
        alloc_new();
    array[vsize]=i;
    vsize++;
}

template<class T>
void myVector<T>::pop_back(){
    array[vsize]=NULL;
    vsize--;
}

template<class T>
int myVector<T>::size(){
    return vsize;
}

template<class T>
T myVector<T>::back(){
    return array[vsize-1];
}

template<class T>
T myVector<T>::operator[](int i){
    return array[i];
}

template<class T>
myVector<T>& myVector<T>::operator=(const myVector& v){
    if(this!=&v){
        maxsize=v.maxsize;
        vsize=v.vsize;
        delete [] array;
        array=new T[maxsize];
        for(int i=0; i<v.size();i++)
            array[i]=v.array[i];
    }
   return  *this;
}

template<class T>
myVector<T>& myVector<T>::operator+=(const T& i)
{
    this->push_back(i);
    return *this;
}

template<class T>
int myVector<T>::at(T& i)
{
    if(i<vsize)
        return array[i];
    throw 10;
}

template<class T>
void myVector<T>::alloc_new(){
    maxsize=vsize*2;
    T* tmp=new T[maxsize];
    for(int i=0;i<vsize;i++)
        tmp[i]=array[i];
    delete[] array;
    array=tmp;
}

#endif // MYVECTOR_H
