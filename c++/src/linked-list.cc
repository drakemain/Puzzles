#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

void test_destructors();

template <class T>
class Node {
private:
  T value;
  Node* next;

public:
  //constructors
  Node(T value) : value(value), next(nullptr) {}

  Node(T value, Node *next) : value(value), next(next) {}
  

  // destructor
  ~Node() {
    delete this->next;
  }


  // getters
  T getValue() {
    return this->value;
  }

  Node* getNext() {
    return this->next;
  }


  // setters
  void setNext(Node* node) {
    this->next = node;
  }
};

template <class T>
class LinkedList {
private:
  Node<T>* head;

public:
  LinkedList(T value) : head(new Node<T>(value)) {}

  LinkedList(Node<T>* node) : head(node) {}

  LinkedList(std::vector<T> values) {
    if (values.size() < 1) {
      throw "Can't build linked list from empty vector.";
    }

    this->head = new Node<T>(values[0]);
    Node<T>* lookingAt = head;

    for (unsigned int i = 1; i < values.size(); i++) {
      lookingAt->setNext(new Node<T>(values[i]));
      lookingAt = lookingAt->getNext();
    }
  }


  ~LinkedList() {
    delete this->head;
  }
  

  /**
   * compares to another list to determine
   * if lists are equal
   * 
   * @param Node*   list to compare to
   * @return bool   true if lists are euqal
   */
  bool isEqual(LinkedList &list) {
    Node<T>* lookingAt = this->head;
    Node<T>* compareTo = list.head;

    while (lookingAt != nullptr && compareTo != nullptr) {
      if (lookingAt->getValue() != compareTo->getValue()) {
        return false;
      }

      lookingAt = lookingAt->getNext();
      compareTo = compareTo->getNext();
    }

    // return false if lists are different length
    return !(lookingAt || compareTo);
  }

  /**
   * append a node to the list
   * 
   * @param int   the value to be appeneded
   */
  void append(T value) {
    Node<T>* lookingAt = this->head;

    while (lookingAt->getNext() != nullptr) {
      lookingAt = lookingAt->getNext();
    }

    lookingAt->setNext(new Node<T>(value));
  }

  /**
   * insert a node into the list
   *
   * @param int   the value to insert
   * @param int   the location to insert to
   */
  void insert(T value, int index) {
    if (index == 0) {
      this->head = new Node<T>(value, this->head);
      return;
    }

    Node<T>* lookingAt = this->head;
    Node<T>* leftOfInsert;
    int currentIndex = 0;

    while (lookingAt != nullptr && currentIndex < index) {
      leftOfInsert = lookingAt;
      lookingAt = lookingAt->getNext();

      currentIndex++;
    }

    if (currentIndex == index) {
      leftOfInsert->setNext(new Node<T>(value));

      if (lookingAt != nullptr) {
        leftOfInsert->getNext()->setNext(lookingAt);
      }
    }
  }

  /**
  * print the contents of the list to ostream
  */
  void printTo(std::ostream &os) {
    Node<T>* lookingAt = head;

    while (lookingAt != nullptr) {
      os << lookingAt->getValue();

      if (lookingAt->getNext() != nullptr) {
        os << " → ";
      }

      lookingAt = lookingAt->getNext();
    }
  }

  /**
   * deletes the first occurence of the input value
   * 
   * @param value   the value to delete from the list
   */
  void deleteByValue(T value) {
    if (this->head == nullptr) {
      return;
    }

    Node<T>* lookingAt = this->head;
    Node<T>* previousNode = nullptr;

    while (lookingAt->getValue() != value) {
      // find the node containing the value to delete
      previousNode = lookingAt;
      lookingAt = lookingAt->getNext();

      if (lookingAt == nullptr) {return;}
    }

    if (previousNode) {
      previousNode->setNext(lookingAt->getNext());
    } else {
      this->head = lookingAt->getNext();
    }

    lookingAt->setNext(nullptr);
    delete lookingAt;
  }
};

int main() {
  test_destructors();

  std::ostringstream listString;

  // construct a list using manually linked nodes
  LinkedList<int>list = LinkedList<int>(new Node<int>(0, new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, nullptr)))))));
  // construct a list using a vector
  LinkedList<int>list1 = LinkedList<int>(std::vector<int> {0, 1, 2, 3, 4, 5});
  // construct a list with a single initial value and inserting/appending
  LinkedList<int>list2 = LinkedList<int>(1); list2.insert(0, 0); list2.insert(2, 2); list2.append(3); list2.append(4); list2.append(5);

  // ensure list contains correct values
  list.printTo(listString);
  assert(listString.str() == "0 → 1 → 2 → 3 → 4 → 5"); listString.str("");

  // make sure all 3 lists are equal
  assert(list.isEqual(list1));
  assert(list.isEqual(list2));

  // test append method
  list.append(6);
  list.printTo(listString);
  assert(listString.str() == "0 → 1 → 2 → 3 → 4 → 5 → 6"); listString.str("");
  assert(!list.isEqual(list1));

  list1.append(6);
  assert(list.isEqual(list1));

  // test insert method
  list.insert(10, 4);
  list.printTo(listString);
  assert(listString.str() == "0 → 1 → 2 → 3 → 10 → 4 → 5 → 6"); listString.str("");
  assert(!list.isEqual(list1));

  // test deleteByValue method
  list.deleteByValue(10);
  list.printTo(listString);
  assert(listString.str() == "0 → 1 → 2 → 3 → 4 → 5 → 6"); listString.str("");
  assert(list.isEqual(list1));

  // test insert() edge case (beginning of list)
  list.insert(10, 0);
  list.printTo(listString);
  assert(listString.str() == "10 → 0 → 1 → 2 → 3 → 4 → 5 → 6"); listString.str("");

  list.insert(20, 8);
  list.printTo(listString);
  assert(listString.str() == "10 → 0 → 1 → 2 → 3 → 4 → 5 → 6 → 20"); listString.str("");

  // test deleteByValue edge cases (beginning and end of list, value DNE)
  list.deleteByValue(10);
  list.printTo(listString);
  assert(listString.str() == "0 → 1 → 2 → 3 → 4 → 5 → 6 → 20"); listString.str("");

  list.deleteByValue(20);
  list.printTo(listString);
  assert(listString.str() == "0 → 1 → 2 → 3 → 4 → 5 → 6"); listString.str("");

  list.deleteByValue(100);
  list.printTo(listString);
  assert(listString.str() == "0 → 1 → 2 → 3 → 4 → 5 → 6"); listString.str("");

  std::cout << "All int list tests passed." << std::endl;

  LinkedList<std::string> stringList = LinkedList<std::string>("Hello"); stringList.append("World.");
  LinkedList<std::string> stringList1 = LinkedList<std::string>(new Node<std::string>("Hello", new Node<std::string>("World.")));

  assert(stringList.isEqual(stringList1));

  stringList.insert(", ", 1);
  assert(!stringList.isEqual(stringList1));

  std::cout << "All string list tests passed." << std::endl;
}

void test_destructors() {
  LinkedList<int>list = LinkedList<int>(std::vector<int> {1, 2, 3});


}