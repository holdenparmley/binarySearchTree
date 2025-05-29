// Holden Parmley, holdenjparmley@gmail.com, hparmley on Pengo                                          
// Header for a binary search tree class                                                                
// Working/tested, no errors or warnings                                                                

#include <utility>
#include <string>

class BinarySearchTree {
 private:
  struct Node;
  Node* root;
  Node* search(Node* x, int k);
  void remove(Node* x);  // Removes a node                                                              
  Node* min(Node* x);  // Min of a subset of the tree                                                   
  Node* max(Node* x);  // Max of a subset of the tree                                                   
  Node* predecessor(Node* x);  // Predecessor for a node                                                
  Node* successor(Node* x);  // Successor for a node                                                    
  std::string inorder(Node* x);  // Inorder traversal from a node reference                             
  std::string preorder(Node* x);  // Preorder traversal from a node reference                           
  std::string postorder(Node* x);  // Postorder traversal from a node reference                         
  void postorderDestroy(Node* x);  // Helper function for destructor                                    
 public:
  BinarySearchTree();
  ~BinarySearchTree();
  bool search(int k);  // User-facing search (true if found, false if not)                              
  void insert(int k);
  bool remove(int k);  // Returns true if node was found and deleted                                    
  std::pair<bool, int> min();  // Returns bool for empty status, int for min                            
  std::pair<bool, int> max();  // Returns bool for empty status, int for max                            
  // Predecessor returns a bool if k is in the tree, a bool for if the predecessor                      
  // exists, and the integer value of the predecessor (0 otherwise)                                     
  std::pair<bool, std::pair<bool, int>> predecessor(int k);
  // Successor does the same thing                                                                      
  std::pair<bool, std::pair<bool, int>> successor (int k);
  std::string inorder();  // User-facing inorder traversal                                              
  std::string preorder();  // User-facing preorder traversal                                            
  std::string postorder();  // User-facing postorder traversal                                          
};
