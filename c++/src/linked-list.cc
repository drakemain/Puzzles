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

  // setters
  void setNext(int value) {
    this->next = new Node(value);
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

  LinkedList(std::vector<int> values) {
    this->head = new Node(values[0]);
    Node* lookingAt = head;

    for(unsigned int i = 1; i < values.size(); i++) {
      lookingAt->setNext(values[i]);
      lookingAt = lookingAt->getNext();
    }
  }


  /**
   * append a value to the list
   * 
   * @param int the value to be appeneded
   */
  void append(int value) {
    Node* lookingAt = head;

    while(lookingAt->getNext() != nullptr) {
      std::cout << lookingAt->getValue();
      lookingAt = lookingAt->getNext();
    }

    lookingAt->setNext(value);
  }

  /**
  * return all values in the list as a string
  * 
  * @return string built from values in the list
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
  LinkedList list = LinkedList(new Node(0, new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr)))))));
  list.append(6);
  list.append(128);

  LinkedList list1 = LinkedList(std::vector<int> {0, 1, 2, 3, 4, 5});

  std::cout << list.toString() << std::endl
    << list1.toString() << std::endl;
}