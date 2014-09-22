#include <iostream>
using namespace std;

typedef struct TNode Node;
typedef struct TLinkedList LinkedList;

struct  TNode {
  Node* next;
  double value;
};

struct TLinkedList {
  Node* head;
  Node* tail;
  int count;
};

LinkedList* createList() {
  LinkedList* list = new LinkedList;
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
  return list;
}

void clearList(LinkedList* list) {
  Node* tmp = NULL;
  while(list->head){
    tmp = list->head;
    list->head = list->head->next;
    delete tmp;
  }
  list->tail = NULL;
  list->count = 0;
}

void deleteList(LinkedList* list){
  clearList(list);
  delete list;
}

void addFirstNode(LinkedList* list, int value){
  Node* node = new Node;
  node->value = value;
  node->next = list->head;
  if(!list->head)
    list->tail = node;
  list->head = node;
  list->count++;
}

void addLastNode(LinkedList* list, int value){
  Node* node = new Node;
  node->value = value;
  node->next = NULL;
  if(!list->head)
    list->head = node;
  else
    list->tail->next = node;
  list->tail = node;
  list->count++;
}

Node* seekAndDestroyEntry(Node* node, int value){
  if(node->value == value){
    Node* tmp = node;
    node = node->next;
    delete tmp;
    return node;
  }
  while (node->next){
    if(node->next->value == value){
      Node* tmp = node->next;
      node->next = node->next->next;
      delete tmp;
      return node->next;
    }
    node = node->next;
  }
  return NULL;
}

void deleteAllEntries(LinkedList* list, int value){
  if(!list->head)
      return;
  if(list->head->value == value){
    Node* tmp = list->head;
    list->head = list->head->next;
    delete tmp;
  }
  Node* node = list->head;
  while(node)
    node = seekAndDestroyEntry(node, value);
}

void deleteFirstEntry(LinkedList* list, int value){
  if(!list->head)
    return;
  if(list->head->value == value){
    Node* tmp = list->head;
    list->head = list->head->next;
    delete tmp;
  }
  seekAndDestroyEntry(list->head, value);
}

void reverseList(LinkedList* list){
  Node* current = list->head;
  Node* previous = NULL;
  while(current){
    Node* tmp = current->next;
    current->next = previous;
    previous = current;
    current = tmp;
  }
  Node* tmp = list->tail;
  list->head = list->tail;
  list->tail = tmp;
}

void printList(LinkedList* list){
  Node* node = list->head;
  while(node){
    cout<<node->value<<' ';
    node = node->next;
  }
  cout << endl;
}

int main(){
  LinkedList* list = createList();
  addLastNode(list, 1);
  addLastNode(list, 14);
  addLastNode(list, 78);
  addLastNode(list, 256);
  addLastNode(list, 78);
  addLastNode(list, 15);
  addFirstNode(list, 8);
  printList(list);

  reverseList(list);
  printList(list);

  deleteAllEntries(list, 78);
  printList(list);

  clearList(list);
  printList(list);

  addLastNode(list, 9);
  printList(list);

  deleteList(list);
  cin.get();
}

