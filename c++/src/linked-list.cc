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

  Node* getNext() {
    return this->next;
  }
};

class LinkedList {
private:
  Node* head;

public:
  LinkedList() {
    this->head = new Node();
  }

  LinkedList(Node* node) {
    this->head = node;
  }


  /**
  * return all values in the list as a string.
  */
  std::string toString() {
    std::string output = "";
    Node* lookingAt = head;

    while(lookingAt != nullptr) {
      output += std::to_string(lookingAt->getValue());

      if (lookingAt->getNext() != nullptr) {
        output += " → ";
      }

      lookingAt = lookingAt->getNext();
    }

    return output;
  }
};

int main() {
  Node nodes = Node(0, new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr))))));
  LinkedList list = LinkedList(&nodes);

  std::cout << list.toString() << std::endl;
}