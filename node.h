#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node{
  T data;
  Node* left;
  Node* right;

  void killself(){
    if (this->left) {
      this->left->killself();
    }else if (this->right) {
      this->right->killself();
    }else delete this;
  }
  void insert(T data){
    if (this->data<data) {
      if (!this->right) {
        Node<T>* temp = new Node<T>{data,nullptr,nullptr};
        this->right = temp;
        temp = nullptr;
        delete temp;
      }else{
        this->right->insert(data);
      }
    }else if (this->data>data) {
      if (!this->left) {
        Node<T>* temp = new Node<T>{data,nullptr,nullptr};
        this->left = temp;
        temp = nullptr;
        delete temp;
      }else{
        this->left->insert(data);
      }
    }
  };
  void printInOrder() {
    if (this->left) {
      this->left->printInOrder();
    }
    std::cout <<this->data <<' ';
    if (this->right) {
      this->right->printInOrder();
    }
  };
  void printPreOrder() {
    std::cout <<this->data <<' ';
    if (this->left) {
      this->left->printPreOrder();
    }
    if (this->right) {
      this->right->printPreOrder();
    }
  };
  void printPostOrder() {
    if (this->left) {
      this->left->printPostOrder();
    }
    if (this->right) {
      this->right->printPostOrder();
    }
    std::cout <<this->data <<' ';
  };
};

#endif
