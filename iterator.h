#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator{
protected:
  Node<T>* current;
public:
  Iterator():current(nullptr){};
  Iterator(Node<T>* current):current(current){};

  bool operator!=(Iterator<T> other){return this->current!=other.current;};
  T operator*(){
    if (current) {
      return this->current->data;
    }else{
      throw("Iterator point nothing");
    }
  };
};

#endif
