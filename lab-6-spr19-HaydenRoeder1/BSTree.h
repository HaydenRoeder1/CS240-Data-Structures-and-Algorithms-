#ifndef BST_HEADER_HR
#define BST_HEADER_HR
#include <vector>
#include <cstdio>
#include <iostream>
template <class T>
class BSTree{
private:
  template <class N>
  class Node{
  public:
      Node<T> * left, * right, * parent;
      N data;
      Node(N data, Node<T> * parent){
        this->data = data;
        this->parent = parent;
        this->left = nullptr;
        this->right = nullptr;
      }
  };
  Node<T> * root;
public:
  BSTree();
  ~BSTree();
  BSTree(const BSTree<T> &old_tree);

  bool empty();

  bool insert(T val);
  void insertNode(T val,Node<T> * n);

  bool find(T val);
  bool findNode(T data, Node<T> * n);

  Node<T> * search(T val);
  Node<T> * searchNode(T data, Node<T> * n);

  void sortedArray(std::vector<T> &list);
  void inorderSort(std::vector<T> &list, Node<T> * n);

  bool remove(T val);
  void removeLeaf(Node<T> * r);
  void shortCircuit(Node<T> * r);
  void promotion(Node<T> * r);

  Node<T> * findMin(Node<T> * r);

  void removeAll(Node<T> * r);
  void deepCopy(Node<T> * r);

  void balance();
  void balanceHelper(std::vector<T> arr, int start, int end);
  int height();
  int findHeight(Node<T> * r);
};

template <class T>
BSTree<T>::BSTree(){
  root = nullptr;
}
template <class T>
BSTree<T>::~BSTree(){
  removeAll(root);
}
template <class T>
BSTree<T>::BSTree(const BSTree &old_tree){
	root = nullptr;
	deepCopy(old_tree.root);
}
template <class T>
bool BSTree<T>::empty(){
  if(root == nullptr){return true;}
  return false;
}
template <class T>
bool BSTree<T>::find(T val){
  if(root == nullptr){
    return false;
  }
  return findNode(val, root);
}
template <class T>
bool BSTree<T>::findNode(T data, Node<T> * n){
  if(data == n->data){
    return true;
  }
  if(data < n->data){
		if(n->left == nullptr){
			return false;
    }
    return findNode(data, n->left);
  }else if(data > n->data){
	  if(n->right == nullptr){
	    return false;
    }
    return findNode(data, n->right);
  }
}
template <class T>
BSTree<T>::Node<T>  * BSTree<T>::search(T val){
  if(!find(val)){return nullptr;}
  return searchNode(val, root);
}
template <class T>
BSTree<T>::Node<T>  * BSTree<T>::searchNode(T data, Node<T> * n){
  if(data == n->data){
    return n;
  }
  if(data < n->data){
    if(n->left == nullptr){
      return nullptr; //Shouldn't get here
    }
    return searchNode(data, n->left);
  }else if(data > n->data){
    if(n->right == nullptr){
      return nullptr; //Shouldn't get here
    }
    return searchNode(data, n->right);
  }
}
template <class T>
bool BSTree<T>::insert(T val){
  if(find(val)){
    return false;
  }
  if(root == nullptr){
    root = new Node<T>(val, nullptr);
  }
  else{
    insertNode(val, root);
  }
  return true;
}

template <class T>
void BSTree<T>::insertNode(T data, Node<T> * n){
  if(data < n->data){
		if(n->left == nullptr){
			n->left = new Node<T>(data, n);
    }
    insertNode(data, n->left);
  }
  else if(data > n->data){
	   if(n->right == nullptr){
	      n->right = new Node<T>(data, n);
      }
      insertNode(data, n->right);
    }
}
template <class T>
void BSTree<T>::sortedArray(std::vector<T> &list){
    inorderSort(list, root);
}
template <class T>
void BSTree<T>::inorderSort(std::vector<T> &list, Node<T> * n){
  if(n != nullptr){
    inorderSort(list, n->left);
    list.push_back(n->data);
    inorderSort(list, n->right);
  }
}
template <class T>
bool BSTree<T>::remove(T val){
  Node<T> * r = search(val);
  if(r == nullptr){return false;}
  if(r->left == nullptr && r->right == nullptr){
    removeLeaf(r);
  }
  else if(r->left == nullptr || r->right == nullptr){
    shortCircuit(r);
  }
  else{
    promotion(r);
  }
  return true;
}
template <class T>
void BSTree<T>::removeLeaf(Node<T> * r){
	if(r == root){
	   	root = nullptr;
  	}
	else if(r == r->parent->right){
		r->parent->right = nullptr;
	}
  	else{
	   	r->parent->left = nullptr;
  	}
 	delete r;
}
template <class T>
void BSTree<T>::shortCircuit(Node<T> * r){
	if(r == root){
		if(r->left == nullptr){
			root = r->right;
			r->right->parent = nullptr;
	   	}else{
		      root = r->left;
		      r->left->parent = nullptr;
	    	}
  	}else if(r == r->parent->left){
		if(r->right==nullptr){
			r->parent->left = r->left;
			r->left->parent = r->parent;
		}else{
			r->parent->left = r->right;
			r->right->parent = r->parent;
     		}
  	}else{
		if(r->right == nullptr){
	 		r->parent->right = r->left;
	 		r->left->parent = r->parent;
     		}else{
	      		r->parent->right = r->right;
	      		r->right->parent = r->parent;
      		}
    	}
    	delete r;
}
template <class T>
void BSTree<T>::promotion(Node<T> * r){
  	Node<T> * min = findMin(r->right);
	r->data = min->data;
    	if(min->left == nullptr && min->right == nullptr){
	     removeLeaf(min);
   	}else if(r->left == nullptr || r->right == nullptr){
	     shortCircuit(min);
   	}
}
template <class T>
BSTree<T>::Node<T> * BSTree<T>::findMin(Node<T> * r){
	if(r->left == nullptr){
		return r;
	}
	return findMin(r->left);
}
template <class T>
void BSTree<T>::removeAll(Node<T> * r){
  root = nullptr;
	if(r != nullptr){
		removeAll(r->left);
		removeAll(r->right);
		delete r;
    r = nullptr;
	}
}
template <class T>
void BSTree<T>::deepCopy(Node<T> * r){

	if(r != nullptr){
		insert(r->data);
		deepCopy(r->left);
		deepCopy(r->right);

	}
}
template <class T>
void BSTree<T>::balance(){
  if(empty()){return;}
  std::vector<T> arr;
  sortedArray(arr);
  removeAll(root);

  balanceHelper(arr, 0, arr.size() - 1);

}
template <class T>
void BSTree<T>::balanceHelper(std::vector<T> arr, int start, int end){
  int center = ((start + end) / 2);
  insert(arr[center]);
  if(center == start || center == end){
    return;
  }
  balanceHelper(arr, start, center - 1);
  balanceHelper(arr, center + 1, end);
}



template <class T>
int BSTree<T>::height(){
        return findHeight(this->root);
}
template <class T>
int BSTree<T>::findHeight(Node<T> * node){

   // base case tree is empty
   if(node == NULL)
       return -1;

   // If tree is not empty then height = 1 + max of left height and right heights
    int lh = findHeight(node->left);
    int rh = findHeight(node->right);
    int max = (lh >= rh) ? lh : rh;

    return max+1;
}

#endif
