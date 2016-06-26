#include <iostream>
#include <string>
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

  std::string pathTo(T value) {
    Node<T>* lookingAt = root;
    std::string output = "";

    while (true) {
      if (lookingAt == nullptr) {
        output += "∅";
        break;
      }

      output += std::to_string(lookingAt->value);

      if (lookingAt->value == value) {
        break; 
      }

      if (value > lookingAt->value) {
        output += " (R)";
        lookingAt = lookingAt->right;
      } else if (value < lookingAt->value) {
        output += " (L)";
        lookingAt = lookingAt->left;
      }

      output += "→ ";
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

  assert(tree.pathTo(4) == "1 (R)→ 2 (R)→ 5 (L)→ 4");
  assert(tree.pathTo(6) == "1 (R)→ 2 (R)→ 5 (R)→ ∅");
  assert(tree.pathTo(0) == "1 (L)→ 0");

  std::cout << "All int binary tree tests passed." << std::endl;
}