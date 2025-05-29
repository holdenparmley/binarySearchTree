#include "binarySearchTree.h"
#include <iostream>

struct BinarySearchTree::Node {
  int key;
  Node* left;
  Node* right;
  Node* parent;
  Node(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

BinarySearchTree::BinarySearchTree() {
  root = nullptr;
}

bool BinarySearchTree::search(int k) {
  // Public search returns true or false                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  BinarySearchTree::Node* x = search(root, k);
  if (x == nullptr) return false;
  return true;
}

BinarySearchTree::Node* BinarySearchTree::search(BinarySearchTree::Node* x, int k) {
  // Private search returns a pointer to a Node, or nullptr if not found                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  if (x == nullptr || x->key == k) return x;
  if (k < x->key) return search(x->left, k);
  return search(x->right, k);
}

void BinarySearchTree::insert(int k) {
  BinarySearchTree::Node* n = new BinarySearchTree::Node(k);
  BinarySearchTree::Node* p = nullptr;
  BinarySearchTree::Node* t = root;
  while (t != nullptr) {
    p = t;
    if (k < t->key) {
      t = t->left;
    } else {
      t = t->right;
    }
  }
  n->parent = p;
  if (p == nullptr) {
    root = n;
    return;
  }
  if (k < p->key) {
    p->left = n;
  } else {
    p->right = n;
  }
}

bool BinarySearchTree::remove(int k) {
  // Public remove returns success status of the private remove function                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  BinarySearchTree::Node* x = search(root, k);
  if (x == nullptr) return false;
  remove(x);
  return true;
}

void BinarySearchTree::remove(BinarySearchTree::Node* x) {
  Node* t = nullptr;  // Must declare t and n outside of if block                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  Node* n = nullptr;
  if (x->left == nullptr || x->right == nullptr) {
    t = x;
  } else {
    t = successor(x);
  }
  if (t->left != nullptr) {
    n = t->left;
  } else {
    n = t->right;
  }
  if (n != nullptr) n->parent = t->parent;
  if (t->parent == nullptr) root = n;
  else if (t == t->parent->left) {
    t->parent->left = n;
  } else {
    t->parent->right = n;
  }
  if (t != x) {
    x->key = t->key;
  }
  delete t;
}

std::pair<bool, int> BinarySearchTree::min() {
  // Bool is false if tree is empty, and second value in pair can be disregarded                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  // If tree is not empty, bool is true, and second value is key of the min                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  if (root == nullptr) return std::make_pair(false, 0);
  return std::make_pair(true, min(root)->key);
}

BinarySearchTree::Node* BinarySearchTree::min(BinarySearchTree::Node* x) {
  while (x->left != nullptr) x = x->left;
  return x;
}

std::pair<bool, int> BinarySearchTree::max() {
  // Same logic as the min function                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
  if (root == nullptr) return std::make_pair(false, 0);
  return std::make_pair(true, max(root)->key);
}

BinarySearchTree::Node* BinarySearchTree::max(BinarySearchTree::Node* x) {
  while (x->right != nullptr) x = x->right;
  return x;
}

std::pair<bool, std::pair<bool, int>> BinarySearchTree::predecessor(int k) {
  // Predecessor returns false as the first value of the pair if the integer k                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
  // is not in the tree at all                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
  // The second value in the pair starts with false if there is no predecessor,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
  // and in this case the integer after can be disregarded                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
  // The second value starts with true if there is a predecessor, and the integer                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  // after it is the value of the predecessor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  BinarySearchTree::Node* x = search(root, k);
  if (x == nullptr) return std::make_pair(false, std::make_pair(false, 0));
  BinarySearchTree::Node* pred = predecessor(x);
  if (pred == nullptr) return std::make_pair(true, std::make_pair(false, 0));
  return std::make_pair(true, std::make_pair(true, pred->key));
}


BinarySearchTree::Node* BinarySearchTree::predecessor(BinarySearchTree::Node* x) {
  if (x->left != nullptr) return max(x->left);
  BinarySearchTree::Node* t = x->parent;
  while (t != nullptr && x == t->left) {
    x = t;
    t = t->parent;
  }
  return t;
}

std::pair<bool, std::pair<bool, int>> BinarySearchTree::successor(int k) {
  // Same logic as predecessor function                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  BinarySearchTree::Node* x = search(root, k);
  if (x == nullptr) return std::make_pair(false, std::make_pair(false, 0));
  BinarySearchTree::Node* succ = successor(x);
  if (succ == nullptr) return std::make_pair(true, std::make_pair(false, 0));
  return std::make_pair(true, std::make_pair(true, succ->key));
}

BinarySearchTree::Node* BinarySearchTree::successor(BinarySearchTree::Node* x) {
  if (x == nullptr) return x;
  if (x->right != nullptr) return min(x->right);
  BinarySearchTree::Node* t = x->parent;
  while (t != nullptr && x == t->right) {
    x = t;
    t = t->parent;
  }
  return t;
}

std::string BinarySearchTree::inorder() {
  return inorder(root);
}

std::string BinarySearchTree::inorder(BinarySearchTree::Node* x) {
  std::string output;
  if (x == nullptr) return output;
  output += inorder(x->left);
  output += std::to_string(x->key);
  output += " ";
  output += inorder(x->right);
  return output;
}

std::string BinarySearchTree::preorder() {
  return preorder(root);
}

std::string BinarySearchTree::preorder(BinarySearchTree::Node* x) {
  std::string output;
  if (x == nullptr) return output;
  output += std::to_string(x->key);
  output += " ";
  output += preorder(x->left);
  output += preorder(x->right);
  return output;
}

std::string BinarySearchTree::postorder() {
  return postorder(root);
}

std::string BinarySearchTree::postorder(BinarySearchTree::Node* x) {
  std::string output;
  if (x == nullptr) return output;
  output += postorder(x->left);
  output += postorder(x->right);
  output += std::to_string(x->key);
  output += " ";
  return output;
}

BinarySearchTree::~BinarySearchTree() {
  postorderDestroy(root);
}

void BinarySearchTree::postorderDestroy(Node* x) {
  // This takes inspiration from the postorder traversal                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  // Traverses through the tree in postorder fashion, deleting each node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
  if (x == nullptr) return;
  postorderDestroy(x->left);
  postorderDestroy(x->right);
  delete x;
}

