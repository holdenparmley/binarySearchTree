// Holden Parmley, holdenjparmley@gmail.com, hparmley on Pengo                                                                                                                                                                                     
// Main function for assignment 7, binary search tree                                                                                                                                                                                              
// Working/tested, no errors or warnings                                                                                                                                                                                                           

#include "binarySearchTree.h"
#include <string>
#include <iostream>

void searchHelper(BinarySearchTree& bst, int num) {
  bool searchResult = bst.search(num);
  if (searchResult == false) {
    std::cout << num << " not found." << std::endl;
  } else {
    std::cout << num << " found." << std::endl;
  }
}

void insertHelper(BinarySearchTree& bst, int num) {
  bst.insert(num);
  std::cout << "inserted " << num << "." << std::endl;
}

void deleteHelper(BinarySearchTree& bst, int num) {
  if (bst.remove(num)) {
    std::cout << "deleted " << num << "." << std::endl;
  } else {
    std::cout << "delete " << num << " - not found." << std::endl;
  }
}

void minHelper(BinarySearchTree& bst) {
  std::pair<bool, int> min = bst.min();
  if (min.first == false) {
    std::cout << "tree empty." << std::endl;
  } else {
    std::cout << "min is " << min.second << "." << std::endl;
  }
}

void maxHelper(BinarySearchTree& bst) {
  std::pair<bool, int> max = bst.max();
  if (max.first == false) {
    std::cout << "tree empty." << std::endl;
  } else {
    std::cout << "max is " << max.second << "." << std::endl;
  }
}

void predecessorHelper(BinarySearchTree& bst, int num) {
  std::pair<bool, std::pair<bool, int>> result = bst.predecessor(num);
  if (result.first == false) std::cout << num << " not in tree." << std::endl;
  else if (result.second.first == false) {
    std::cout << "no predecessor for " << num << "." << std::endl;
  } else {
    std::cout << num << " predecessor is " << result.second.second << "." << std::endl;
  }
}

void successorHelper(BinarySearchTree& bst, int num) {
  std::pair<bool, std::pair<bool, int>> result = bst.successor(num);
  if (result.first == false) std::cout << num << " not in tree." << std::endl;
  else if (result.second.first == false) {
    std::cout << "no successor for " << num << "." << std::endl;
  } else {
    std::cout << num << " successor is " << result.second.second << "." << std::endl;
  }
}

void inorderHelper(BinarySearchTree& bst) {
  std::cout << "inorder traversal:" << std::endl;
  std::cout << bst.inorder() << std::endl;
}

void preorderHelper(BinarySearchTree& bst) {
  std::cout << "preorder traversal:" << std::endl;
  std::cout << bst.preorder() << std::endl;
}

void postorderHelper(BinarySearchTree& bst) {
  std::cout << "postorder traversal:" << std::endl;
  std::cout << bst.postorder() << std::endl;
}

int main() {
  BinarySearchTree bst;
  std::string line;
  while (std::getline(std::cin, line)) {
    int poundLocation = line.find('#');
    if (poundLocation != std::string::npos) line = line.substr(0, poundLocation);
    std::string command;
    std::string num;
    int spaceLocation = line.find(' ');
    if (spaceLocation != std::string::npos) {
      command = line.substr(0, spaceLocation);
      num = line.substr(spaceLocation);
    } else {
      command = line;
    }
    if (command == "search") searchHelper(bst, std::stoi(num));
    else if (command == "insert") insertHelper(bst, std::stoi(num));
    else if (command == "delete") deleteHelper(bst, std::stoi(num));
    else if (command == "min") minHelper(bst);
    else if (command == "max") maxHelper(bst);
    else if (command == "predecessor") predecessorHelper(bst, std::stoi(num));
    else if (command == "successor") successorHelper(bst, std::stoi(num));
    else if (command == "inorder") inorderHelper(bst);
    else if (command == "preorder") preorderHelper(bst);
    else if (command == "postorder") postorderHelper(bst);
  }
}
