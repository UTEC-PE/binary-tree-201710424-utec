#ifndef INORDERITERATOR_H
#define INORDERITERATOR_H

#include "iterator.h"
#include <stack>
using namespace std;

template <class T> // Muy bien!
class InOrderIterator : public Iterator<T> {
private:
  stack<Node<T>*> pila;
  void pushLeftChildren() {
    while (this->current) {
      pila.push(this->current);
      this->current = this->current->left;
    }
  }
public:
  InOrderIterator():Iterator<T>() {};
  InOrderIterator(Node<T> *current){
    this->current=current;
    this->pushLeftChildren();
    if (!this->pila.empty()) {
      this->current = this->pila.top();
    }
  };

  InOrderIterator<T> operator=(InOrderIterator<T> other){
    this->current=other.current;
    this->pila=other.pila;
    return *this;
  };
  InOrderIterator<T> operator++(){
    if (!this->current) {
      throw("The iterator point nothing");
    }
    if (!pila.empty()) {
      pila.pop();
      this->current=this->current->right;
      this->pushLeftChildren();
      if (!this->pila.empty()) {
        this->current = this->pila.top();
      }
    }
    return *this;
  };
};

#endif
