#ifndef BTREE_h
#define BTREE_h

#include "node.h"
#include "inorderiterator.h"
#include <iostream>

template <typename T>
class Btree{
public:
  typedef InOrderIterator<T> ioiterator;
private:
  Node<T>* root;
  void removePrivate(T data, Node<T>* parent) {
    if (this->root) {
      if (parent->data == data) {
        removeRootCase();
      } else {
        if (data < parent->data && parent->left) {
          if (parent->left->data == data) {
            removeOtherCase(parent, parent->left, true);
          }else{
            removePrivate(data, parent->left);
          }
        }else if (data > parent->data && parent->right) {
          if (parent->right->data == data) {
            removeOtherCase(parent, parent->right, false);
          }else{
            removePrivate(data, parent->right);
          }
        }else{
          throw("Tryieng to remove an nonexistent");
        }
      }
    } else throw("The tree is empty");
  };
  void removeRootCase() {
    if (this->root) {
      Node<T>* nodeToRemove = this->root;
      //0 children case
      if (!(this->root->right || this->root->left)) {
        this->root=nullptr;
        delete nodeToRemove;
      }else //1 child case
      if (!(this->root->right && this->root->right)) {
        if (this->root->right) {
          this->root=this->root->right;
          delete nodeToRemove;
        }else{
          this->root=this->root->left;
          delete nodeToRemove;
        }
      } //2 children case
      else{
        nodeToRemove = this->root->right;
        while (nodeToRemove->left) {
          nodeToRemove=nodeToRemove->left;
        }
        int smallestInRigthSubtree = nodeToRemove->data;
        removePrivate(smallestInRigthSubtree, this->root);
        this->root->data = smallestInRigthSubtree;
      }
    }else{
      throw("Binary tree is empty");
    }
  };
  void removeOtherCase(Node<T>* parent, Node<T>* nodeToRemove, bool left) {
    if (this->root) {
      //0 children case
      if (!(nodeToRemove->right || nodeToRemove->left)) {
        left ? parent->left=nullptr : parent->right = nullptr;
        delete nodeToRemove;
      }else //1 child case
      if (!(nodeToRemove->right && nodeToRemove->right)) {
        if (nodeToRemove->right) {
          left ? parent->left=nodeToRemove->right : parent->right=nodeToRemove->right;
          delete nodeToRemove;
        }else{
          left ? parent->left=nodeToRemove->left : parent->right=nodeToRemove->left;
          delete nodeToRemove;
        }
      } //2 children case
      else{
        Node<T>* temp = nodeToRemove;
        nodeToRemove = nodeToRemove->right;
        while (nodeToRemove->left) {
          nodeToRemove=nodeToRemove->left;
        }
        int smallestInRigthSubtree = nodeToRemove->data;
        removePrivate(smallestInRigthSubtree, temp);
        temp->data = smallestInRigthSubtree;
      }
    }else throw("Tree is empty");
  }
public:
  Btree(){
    this->root = nullptr;
  };

  int weigth(){
    int weigth = 0;
    for (auto i = this->begin(); i != this->end(); ++i) {
      weigth++;
    }
    return weigth;
  }
  void insert(T data){
    if (!this->root) {
      Node<T>* temp = new Node<T>{data,nullptr,nullptr};
      this->root=temp;
      temp = nullptr;
      delete temp;
    }else{
      this->root->insert(data);
    }
  };
  void remove(T data) {
    removePrivate(data, this->root);
  };
  void printInOrder() {
    if (this->root) {
      if (this->root->left) {
        this->root->left->printInOrder();
      }
      std::cout<<this->root->data<<' ';
      if (this->root->right) {
        this->root->right->printInOrder();
      }
      std::cout<<'\n';
    }
  };
  void printPreOrder() {
    if (this->root) {
      std::cout<<this->root->data<<' ';
      if (this->root->left) {
        this->root->left->printPreOrder();
      }
      if (this->root->right) {
        this->root->right->printPreOrder();
      }
      std::cout<<'\n';
    }
  };
  void printPostOrder() {
    if (this->root) {
      if (this->root->left) {
        this->root->left->printPostOrder();
      }
      if (this->root->right) {
        this->root->right->printPostOrder();
      }
      std::cout<<this->root->data<<' ';
      std::cout<<'\n';
    }
  };

  ioiterator begin() {
    if (!this->root) {
      throw("The binary tree is empty.");
    } else {
      return ioiterator(this->root);
    }
  };
  ioiterator end() {return ioiterator(nullptr);};

  ~Btree(){
    if (root) {
      this->root->killself(); 
    }
  };
};

#endif

//TODO
//Eliminar (3 casos)
