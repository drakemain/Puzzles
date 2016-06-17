#include <iostream>
#include <string>
#include <vector>

class Node {
private:
  int value;
  Node* next;

public:
  //constructors
  Node() {
    next = nullptr;
  };

  Node(int value) {
    this->value = value;
    this->next = nullptr;
  }

  Node(int value, Node *next) {
    this->value = value;
    this->next = next;
  }

  // destructor
  ~Node() {
    if (this->next) {
      delete this->next;
    }
  }
  

  // getters
  int getValue() {
    return this->value;
  }
};


int main() {
  Node heapList = Node(0, new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr))))));

  std::cout << heapList.toString() << std::endl;
}
