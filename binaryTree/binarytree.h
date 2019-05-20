/****
 * This Binary Tree class has been adapted from Paul Wilkinson's CS008 lectures.
 *
 * @author      Rafael Betita
 * @modified    05-16-2019
 ****/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"
#include <iomanip>
#include <algorithm>

namespace bst {

enum class BST_TRAVERSAL{PRE_ORDER, IN_ORDER, POST_ORDER, BACKWARD_IN_ORDER};
enum class BST_ERRORS{EMPTY};

template <typename T>
class BinaryTree
{
 public:
  BinaryTree() : root_(nullptr), traversal_(BST_TRAVERSAL::IN_ORDER) {}
  BinaryTree(const T &data, const unsigned int &count);
  BinaryTree(const BinaryTree<T> &other);
  ~BinaryTree();
  BinaryTree<T> &operator=(const BinaryTree<T> &other);

  BinaryTree<T>& operator<<(const T & data);
//  void Insert(const T &data, const unsigned int &count = 1);
  bool Delete(const T &data, const unsigned int &count = 1);
  Node<T>* Insert(Node<T>* root, const T &data,
                     const unsigned int &p, const unsigned int &l);
  void InsertData(const T &data, const unsigned int &p, const unsigned int &l);
  Node<T> ExtractSmallest();

  // Const members
  bool empty() {return !root_;}
  int height() const {return height(root_);}
  const Node<T>* root() const {return root_;}
  Node<T>* root() {return root_;}
  BST_TRAVERSAL traversal() const {return traversal_;}
  unsigned int data_count() const {return data_count(root_);}
  unsigned int node_count() const {return node_count(root_);}

  template <typename S>
  friend
  std::ostream& operator<<(std::ostream& out, const BinaryTree<S> &other);

  template <typename S>
  friend
  std::istream& operator>>(std::istream& in, BinaryTree<S> &other);

 private:
  Node<T> *root_;
  BST_TRAVERSAL traversal_;

  Node<T>* RotateLeft(Node<T> *root);
  Node<T>* RotateRight(Node<T> *root);
  Node<T>* RotateLeftRight(Node<T> *root);
  Node<T>* RotateRightLeft(Node<T> *root);

  void ClearTree(Node<T>*& root);
  void CopyTree(const Node<T>& root);
  Node<T> DeleteLeftChild(Node<T>* &child, Node<T>* &parent);
  void DeleteRightChild(Node<T>* &child, Node<T>* &parent);

  Node<T>* rebalance(Node<T>* root);
  int height(Node<T>* root) const;
  int balance_factor(Node<T>* root) const;
  unsigned int data_count(Node<T>* root) const;
  unsigned int node_count(Node<T>* root) const;
  void PrintTree(std::ostream &out, Node<T>* root) const;
  Node<T>* Find(const T& data, Node<T> *root, Node<T>* &parent, bool &less_than) const;
  Node<T>* FindSmallest(Node<T>* root) const;
  void PrintTreeDepth(std::ostream &out, Node<T>* root, size_t depth) const;


};

#include "binarytree.tpp"

} // end namespace bst

#endif // BINARYTREE_H