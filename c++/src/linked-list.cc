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
    this->next = nullptr;
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

  void setNextNode(Node* node) {
    this->next = node;
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
    if (values.size() < 1) {
      throw "Can't build linked list from empty vector.";
    }

    this->head = new Node(values[0]);
    Node* lookingAt = head;

    for (unsigned int i = 1; i < values.size(); i++) {
      lookingAt->setNext(values[i]);
      lookingAt = lookingAt->getNext();
    }
  }


  /**
   * append a node to the list
   * 
   * @param int   the value to be appeneded
   */
  void append(int value) {
    Node* lookingAt = this->head;

    while (lookingAt->getNext() != nullptr) {
      lookingAt = lookingAt->getNext();
    }

    lookingAt->setNext(value);
  }

  /**
   * insert a node into the list
   *
   * @param int   the value to insert
   * @param int   the location to insert to
   */
  void insert(int value, int index) {
    if (index == 0) {
      this->head = new Node(value, this->head);
      return;
    }

    Node* lookingAt = this->head;
    Node* leftOfInsert;
    int currentIndex = 0;

    while (lookingAt != nullptr && currentIndex < index) {
      leftOfInsert = lookingAt;
      lookingAt = lookingAt->getNext();

      currentIndex++;
    }

    if (currentIndex == index) {
      leftOfInsert->setNext(value);

      if (lookingAt != nullptr) {
        leftOfInsert->getNext()->setNextNode(lookingAt);
      }
    }
  }

  /**
  * return all values in the list as a string
  * 
  * @return string built from values in the list
  */
  std::string toString() {
    std::string output = "";
    Node* lookingAt = head;

    while (lookingAt != nullptr) {
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
  LinkedList list1 = LinkedList(std::vector<int> {0, 1, 3, 4, 6});

  list.append(6);
  list.append(128);
  list.insert(8, 8);

  list1.insert(2, 2);
  list1.insert(5, 5);
  list1.insert(10, 0);

  std::cout << list.toString() << std::endl
    << list1.toString() << std::endl;
}