#include <iostream>
#include <conio.h>
using namespace std;

int main(){
  struct  TNode {
      Node *next;
      double value;
  };
  struct TLinkedList {
      Node *head;
      int count;
  };
  typedef Node struct TNode;
  typedef LinkedList struct TLinkedList;
  LinkedList* create() {
    LinkedList *list = new LinkedList;
    list -> head = null;
    list -> count = 3;
    return list;
  }
}
