#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

template <typename T>
class Node {
private:
  T value;
  Node* left = nullptr;
  Node* right = nullptr;

public:
  Node(T value) : value(value) {}

  Node(T value, Node* left, Node* right)
    : value(value), left(left), right(right) {}


  ~Node() {
    delete this->left;
    delete this->right;
    std::cout<<"NODE DESTR: " << this->value << std::endl;
  }


  T getValue() {
    return this->value;
  }

  Node* getLeft() {
    return this->left;
  }

  Node* getRight() {
    return this->right;
  }

  void setLeft(Node* node) {
    this->left = node;
  }

  void setRight(Node* node) {
    this->right = node;
  }
};

template <typename T>
class Tree {
private:
  Node<T>* root;

public:
  Tree(T value) : root(new Node<T>(value)) {}


  ~Tree() {
    delete this->root;
    std::cout<<"TREE DESTR"<<std::endl;
  }


  void pathTo(T value, std::ostream &os) {
    Node<T>* lookingAt = this->root;

    while (true) {
      if (lookingAt == nullptr) {
        os << "∅";
        break;
      }

      os << lookingAt->getValue();

      if (lookingAt->getValue() == value) {
        break; 
      }

      if (value > lookingAt->getValue()) {
        os << " (R)";
        lookingAt = lookingAt->getRight();
      } else if (value < lookingAt->getValue()) {
        os << " (L)";
        lookingAt = lookingAt->getLeft();
      }

      os << "→ ";
    }
  }

  void insert(T value) {
    Node<T>* lookingAt = this->root;

    while (true) {
      if (value > lookingAt->getValue()) {
        // look right
        if (lookingAt->getRight() == nullptr) {
          lookingAt->setRight(new Node<T>(value));
          return;
        } else {
          lookingAt = lookingAt->getRight();
        }

      } else if (value < lookingAt->getValue()) {
        // look left
        if (lookingAt->getLeft() == nullptr) {
          lookingAt->setLeft(new Node<T>(value));
          return;
        } else {
          lookingAt = lookingAt->getLeft();
        }
      
      } else if (value == lookingAt->getValue()) {
        return;
      }
    }
  }

  // void deleteByValue(T value) {
  //   Node* lookingAt = this->root;

  //   while (lookingAt-> != )
  // }
};

int main() {
  Tree<int> tree = Tree<int>(1); tree.insert(0); tree.insert(2); tree.insert(5); tree.insert(4);

  std::ostringstream pathString;

  tree.pathTo(4, pathString);
  assert(pathString.str() == "1 (R)→ 2 (R)→ 5 (L)→ 4");
  pathString.str("");

  tree.pathTo(6, pathString);
  assert(pathString.str() == "1 (R)→ 2 (R)→ 5 (R)→ ∅");
  pathString.str("");

  tree.pathTo(0, pathString);
  assert(pathString.str() == "1 (L)→ 0");
  pathString.str("");

  std::cout << "All int binary tree tests passed." << std::endl;

  Tree<std::string> stringTree = Tree<std::string>("Hello"); stringTree.insert("World");

  stringTree.pathTo("World", pathString); 

  assert(pathString.str() == "Hello (R)→ World");

  std::cout << "All string binary tree tests passed." << std::endl;
}