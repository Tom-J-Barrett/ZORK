#ifndef ADDOBJECTS_H
#define ADDOBJECTS_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <QDebug>

using namespace std;

template <class T>
class AddObjects {

   private:
      vector<T> elems;
      T first,second;// elements

   public:
      AddObjects(T first, T second);
    //  void operator++();
      void push(T const&);  // push element
      void pop();               // pop element
      void test();
      T top() const;            // return top element
      bool empty() const{       // return true if empty.
         return elems.empty();
      }
};
#endif // ADDOBJECTS_H
