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
  }
};

template <typename T>
class Tree {
private:
  Node<T>* root;

public:
  Tree() {}

  Tree(T value) : root(new Node<T>(value)) {}


  ~Tree() {
    delete this->root;
  }


  void pathTo(T value, std::ostream &os) {
    Node<T>* lookingAt = this->root;

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
    if (this->root == nullptr) {this->root = new Node<T>(value);return;}

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

  void deleteByValue(T value) {
    if (this->root == nullptr) {return;}

    Node<T>* lookingAt = this->root;
    Node<T>** previousPtr = nullptr;

    while (lookingAt->value != value) {

      if (value > lookingAt->value) {
        previousPtr = &lookingAt->right;
        lookingAt = lookingAt->right;
      } else if (value < lookingAt->value) {
        previousPtr = &lookingAt->left;
        lookingAt = lookingAt->left;
      }

      if (lookingAt == nullptr) {return;}
    }

    this->detatchNode(lookingAt, previousPtr);

    delete lookingAt;
  }

private:
  T getNextLargestValue(Node<T>* startingNode) {
    Node<T>* lookingAt = startingNode;

    lookingAt = lookingAt->right;

    while (lookingAt->left != nullptr) {
      lookingAt = lookingAt->left;
    }

    return lookingAt->value;
  }

  void detatchNode(Node<T>* nodeToDelete, Node<T>** ptrToNode) {
    if (nodeToDelete->right == nullptr && nodeToDelete->left == nullptr) {
      if (ptrToNode == nullptr) {this->root = nullptr;} 
      else {*ptrToNode = nullptr;}      

    } else if (nodeToDelete->right != nullptr && nodeToDelete->left != nullptr) {
      T swapValue = this->getNextLargestValue(nodeToDelete);
      this->deleteByValue(swapValue);

      if(ptrToNode == nullptr) {
        Node<T>* newRoot = new Node<T>(swapValue, nodeToDelete->left, nodeToDelete->right);
        this->root = newRoot;   
      } else {
        *ptrToNode = new Node<T>(swapValue, nodeToDelete->left, nodeToDelete->right);        
      }

      nodeToDelete->left = nullptr;
      nodeToDelete->right = nullptr;
      
    } else if (nodeToDelete->right) {
      if (ptrToNode == nullptr) {this->root = nodeToDelete->right;} 
      else {*ptrToNode = nodeToDelete->right;}
      
      nodeToDelete->right = nullptr;

    } else if (nodeToDelete->left) {
      if (ptrToNode == nullptr) {this->root = nodeToDelete->left;} 
      else {*ptrToNode = nodeToDelete->left;}
      
      nodeToDelete->left = nullptr;
    }
  }
};

template <typename T>
void testPathTo(Tree<T> &tree, T value, std::string expectedPath);

int main() {
  Tree<int> tree = Tree<int>(8); tree.insert(3); tree.insert(10); tree.insert(1); tree.insert(6);
    tree.insert(6); tree.insert(14); tree.insert(4); tree.insert(7); tree.insert(13);

  Tree<int> tree1 = Tree<int>(8); tree1.insert(3); tree1.insert(10); tree1.insert(1); tree1.insert(6);
    tree1.insert(6); tree1.insert(14); tree1.insert(4); tree1.insert(7); tree1.insert(13);

  Tree<int> linearTreeRight = Tree<int>(8); linearTreeRight.insert(10); linearTreeRight.insert(14);
    linearTreeRight.insert(15);

  Tree<int> singleNodeTree = Tree<int>(8);

  // test insert working as expected; path to leaf nodes
  testPathTo(tree, 1, "8 (L)→ 3 (L)→ 1");
  testPathTo(tree, 4, "8 (L)→ 3 (R)→ 6 (L)→ 4");
  testPathTo(tree, 7, "8 (L)→ 3 (R)→ 6 (R)→ 7");
  testPathTo(tree, 13, "8 (R)→ 10 (R)→ 14 (L)→ 13");

  // test path to nodes that don't exist
  testPathTo(tree, 15, "8 (R)→ 10 (R)→ 14 (R)→ ∅");
  testPathTo(tree, 2, "8 (L)→ 3 (L)→ 1 (R)→ ∅");

  // test deleting leaf nodes
  tree.deleteByValue(13);
  testPathTo(tree, 13, "8 (R)→ 10 (R)→ 14 (L)→ ∅");
  
  // test deleting nodes with single child
  tree.deleteByValue(10);
  testPathTo(tree, 10, "8 (R)→ 14 (L)→ ∅");
  linearTreeRight.deleteByValue(10);
  testPathTo(linearTreeRight, 15, "8 (R)→ 14 (R)→ 15");

  // test deleting nodes with two children
  tree.deleteByValue(6);
  testPathTo(tree, 4, "8 (L)→ 3 (R)→ 7 (L)→ 4");
  tree.deleteByValue(3);
  testPathTo(tree, 7, "8 (L)→ 4 (R)→ 7");

  // test deleting root node with two children
  tree1.deleteByValue(8);
  testPathTo(tree1, 7, "10 (L)→ 3 (R)→ 6 (R)→ 7");
  testPathTo(tree1, 13, "10 (R)→ 14 (L)→ 13");

  // test deleting root node with one child
  linearTreeRight.deleteByValue(8);
  testPathTo(linearTreeRight, 15, "14 (R)→ 15");

  // test deleting root node with no children
  singleNodeTree.deleteByValue(8);
  testPathTo(singleNodeTree, 8, "∅");

  std::cout << "All int binary tree tests passed." << std::endl;

  Tree<std::string> stringTree = Tree<std::string>("Hello"); stringTree.insert("World");

  testPathTo(stringTree, std::string("World"), "Hello (R)→ World");

  std::cout << "All string binary tree tests passed." << std::endl;
}

template <typename T>
void testPathTo(Tree<T> &tree, T value, std::string expectedPath) {
  std::ostringstream pathString;

  tree.pathTo(value, pathString);

  assert(pathString.str() == expectedPath);
}