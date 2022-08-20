#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

class Ulist {
  Node *head;

public:
  Ulist() { this->head = NULL; }
  void insert(int val) {
    Node *node = new Node(val);
    if (head == NULL) {
      head = node;
      cout << "NULL WALA HEAD" << endl;
    } else {
      Node *temphead = head;
      while (temphead->next != NULL) {
        temphead = temphead->next;
      }
      temphead->next = node;
    }
  }
  void print() {
    Node *temphead = head;
    while (temphead->next != NULL) {
      cout << temphead->data << "->";
      temphead = temphead->next;
    }
    cout << temphead->data << "->NULL" << endl;
  }
};

int main() {
  Ulist *li = new Ulist();
  li->insert(1);
  li->insert(2);
  li->insert(3);
  li->print();
  return 0;
}
