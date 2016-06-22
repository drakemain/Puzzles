#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Node {
private:
  int value;
  Node* next;

public:
  //constructors
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
  LinkedList(int value) {
    this->head = new Node(value);
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
   * compares to another list to determine
   * if lists are equal
   * 
   * @param Node*   list to compare to
   * @return bool   true if lists are euqal
   */
  bool isEqual(LinkedList* list) {
    Node* lookingAt = this->head;
    Node* compareTo = list->head;

    while (lookingAt != nullptr && compareTo != nullptr) {
      if (lookingAt->getValue() != compareTo->getValue()) {
        return false;
      }

      lookingAt = lookingAt->getNext();
      compareTo = compareTo->getNext();
    }

    if (lookingAt || compareTo) {
      // lists are different length
      return false;
    } else {
      return true;
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

  /**
   * deletes the first occurence of the input value
   * 
   * @param value   the value to delete from the list
   */
  void deleteValue(int value) {
    if (this->head == nullptr) {
      return;
    } else if (this->head->getValue() == value) {
      this->head = this->head->getNext();
    }

    Node* lookingAt = this->head->getNext();
    Node* previousNode = this->head;

    while (lookingAt != nullptr) {
      if (lookingAt->getValue() == value) {
        if (lookingAt->getNext() != nullptr) {
          previousNode->setNextNode(lookingAt->getNext());
        } else {
          previousNode->setNextNode(nullptr);
        }

        return;
      }

      previousNode = lookingAt;
      lookingAt = lookingAt->getNext();
    }
  }
};

int main() {
  LinkedList list = LinkedList(new Node(0, new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, nullptr)))))));
  LinkedList list1 = LinkedList(std::vector<int> {0, 1, 2, 3, 4, 5});
  LinkedList list2 = LinkedList(1);

  assert(list.isEqual(&list1));

  list.append(6);
  assert(!list.isEqual(&list1));

  list1.append(6);
  assert(list.isEqual(&list1));

  list.insert(10, 4);
  assert(!list.isEqual(&list1));

  list.deleteValue(10);
  assert(list.isEqual(&list1));

  std::cout << "All tests passed." << std::endl;
}