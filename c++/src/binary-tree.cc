#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

template <typename T>
struct Node {
  T value;
  Node* left = nullptr;
  Node* right = nullptr;

  
  Node(T value) : value(value) {}

  Node(T value, Node* left, Node* right)
    : value(value), left(left), right(right) {}


  ~Node() {
    delete this->left;
    delete this->right;
    std::cout<<"NODE DESTR: " << this->value << std::endl;
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
    Node<T>* lookingAt = root;

    while (true) {
      if (lookingAt == nullptr) {
        os << "∅";
        break;
      }

      os << lookingAt->value;

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
  }

  void insert(T value) {
    Node<T>* lookingAt = this->root;

    while (true) {
      if (value > lookingAt->value) {
        // look right
        if (lookingAt->right == nullptr) {
          lookingAt->right = new Node<T>(value);
          return;
        } else {
          lookingAt = lookingAt->right;
        }

      } else if (value < lookingAt->value) {
        // look left
        if (lookingAt->left == nullptr) {
          lookingAt->left = new Node<T>(value);
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

  Tree<std::string> stringTree = Tree<std::string>("Hello"); stringTree.insert("World");

  stringTree.pathTo("World", pathString); 

  assert(pathString.str() == "Hello (R)→ World");

  std::cout << "All string binary tree tests passed." << std::endl;
}