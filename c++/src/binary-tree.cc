#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

template <typename T>
struct Node {
  T value;
  Node* left;
  Node* right;
};

template <typename T>
class Tree {
private:
  Node<T>* root;

public:
  Tree(T value) {
    this->root = new Node<T>;
    this->root->value = value;
    this->root->left = nullptr;
    this->root->right = nullptr;
  }

  std::string pathTo(T value, std::ostream &os) {
    Node<T>* lookingAt = root;
    std::string output = "";

    while (true) {
      if (lookingAt == nullptr) {
        os << "∅";
        break;
      }

      os << std::to_string(lookingAt->value);

      if (lookingAt->value == value) {
        break; 
      }

      if (value > lookingAt->value) {
        os << " (R)";
        lookingAt = lookingAt->right;
      } else if (value < lookingAt->value) {
        os << " (L)";
        lookingAt = lookingAt->left;
      }

      os << "→ ";
    }

    return output;
  }

  void insert(T value) {
    Node<T>* lookingAt = this->root;

    while (true) {
      if (value > lookingAt->value) {
        // look right
        if (lookingAt->right == nullptr) {
          lookingAt->right = new Node<T>;
          lookingAt->right->value = value;
          return;
        } else {
          lookingAt = lookingAt->right;
        }

      } else if (value < lookingAt->value) {
        // look left
        if (lookingAt->left == nullptr) {
          lookingAt->left = new Node<T>;
          lookingAt->left->value = value;
          return;
        } else {
          lookingAt = lookingAt->left;
        }
      
      } else if (value == lookingAt->value) {
        return;
      }
    }
  }
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
}