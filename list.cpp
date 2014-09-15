#include <iostream>
using namespace std;

struct  TNode {
  Node* next;
  double value;
};

struct TLinkedList {
  Node* head;
  int count;
};

typedef struct TNode Node;
typedef struct TLinkedList LinkedList;

LinkedList* create() {
  LinkedList* list = new LinkedList;
  list->head = NULL;
  list->count = 3;
  return list;
}

int main(){
  cin.get();
}
