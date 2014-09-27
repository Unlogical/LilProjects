#include <iostream>
#include <fstream>
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

Node* createNode(int value, Node* next){
  Node* node = new Node;
  node->value = value;
  node->next = next;
  return node;
}

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
  Node* node = createNode(value,list->head);
  if(!list->head)
    list->tail = node;
  list->head = node;
  list->count++;
}

void addLastNode(LinkedList* list, int value){
  Node* node = createNode(value,NULL);
  if(!list->head)
    list->head = node;
  else
    list->tail->next = node;
  list->tail = node;
  list->count++;
}

Node* seekAndDestroyEntry(Node* node, int value){
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
  while(list->head->value == value){
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
  list->tail = list->head;
  list->head = previous;
}

void printList(LinkedList* list){
  Node* node = list->head;
  cout<<"[ ";
  while(node){
    cout<<node->value<<' ';
    node = node->next;
  }
  cout<<"]"<<endl;
}

int main(){
  LinkedList* list = createList();
  int value = 0,
          i = 0;
  ifstream file("input.txt");
  while (file >> value){
    if(i % 2 == 0)
      addFirstNode(list, value);
    else 
      addLastNode(list, value);
    i++;
  }
  file.close();
  cout<<"List from file:"<<endl;
  printList(list);
 
  reverseList(list);
  cout<<"Reversed list:"<<endl;
  printList(list);

  reverseList(list);
  cout<<"Reversed back list:"<<endl;
  printList(list);

  deleteFirstEntry(list, 8);
  cout<<"List without first 8:"<<endl;
  printList(list);
 
  deleteAllEntries(list, 8);
  cout<<"List without 8:"<<endl;
  printList(list);

  reverseList(list);
  cout<<"Reversed list:"<<endl;
  printList(list);

  clearList(list);
  cout<<"Empty list:"<<endl;
  printList(list);
  deleteList(list);
  cin.get();
}

