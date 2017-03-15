#include "addobjects.h"


/*template<class T>
void AddObjects<T>::operator++()
{
    qDebug()<<"overload operator";
}


template<class T>
AddObjects<T>::AddObjects(T first, T second)
{
    this->first=first;
    this->second=second;
}*/

template <class T>
void AddObjects<T>::push (T const& elem) {
   // append copy of passed element
   elems.push_back(elem);
}

template <class T>
void AddObjects<T>::pop () {
   if (elems.empty()) {
      throw out_of_range("Stack<>::pop(): empty stack");
   }

   // remove last element
   elems.pop_back();
}

template<class T>
void AddObjects<T>::test()
{
     qDebug()<<"called";
}

template <class T>
T AddObjects<T>::top () const {
   if (elems.empty()) {
      throw out_of_range("Stack<>::top(): empty stack");
   }

   // return copy of last element
   return elems.back();
}
