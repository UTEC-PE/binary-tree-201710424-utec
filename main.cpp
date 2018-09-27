//powered by apu.mp
#include <iostream>
#include "btree.h"

int main(int argc, char const *argv[]) {
  Btree<int> arbolito;
  int test_insert[10] = {35,45,24,35,10,209,34,25,30,90};
  for (int i = 0; i < 10; i++) {
    arbolito.insert(test_insert[i]);
  }
  cout <<"InOrderIterator: ";
  for (auto i = arbolito.begin(); i != arbolito.end(); ++i) {
    cout << *i << ' ';
  }
  cout<<'\n';
  cout <<"weigth: " <<arbolito.weigth() <<'\n';
  cout <<"printInOrder: ";
  arbolito.printInOrder();
  cout <<"printPreOrder: ";
  arbolito.printPreOrder();
  cout <<"printPostOrder: ";
  arbolito.printPostOrder();
  cout <<"\nRemove: 24,209 \n";
  int test_remove[2] = {24,209};
  for (int i = 0; i < 2; i++) {
    arbolito.remove(test_remove[i]);
  }
  cout <<"InOrderIterator: ";
  for (auto i = arbolito.begin(); i != arbolito.end(); ++i) {
    cout << *i << ' ';
  }
  cout<<'\n';
  cout <<"weigth: " <<arbolito.weigth() <<'\n';
  cout <<"printInOrder: ";
  arbolito.printInOrder();
  cout <<"printPreOrder: ";
  arbolito.printPreOrder();
  cout <<"printPostOrder: ";
  arbolito.printPostOrder();
  return 0;
}
