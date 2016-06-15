#include <iostream>
#include <string>

class Node {
private:
  int value;
  Node* next;

public:
  Node() {
    next = nullptr;
  };

  Node(int value) {
    this->value = value;
    next = nullptr;
  }

  // getters
  int getValue() {
    return this->value;
  }
};

int main() {
  Node test(1);

  std::cout << test.getValue();
}