//  Check if a Binary Tree is BST
// Send Feedback
// Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
// Note: Duplicate elements should be kept in the right subtree.
// Input format :

// The first line of input contains data of the nodes of the tree in level order form. The data of the
// nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its 
// place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

// Output format :

// The first and only line of output contains either true or false.

// Constraints :

// Time Limit: 1 second

// Sample Input 1 :

// 3 1 5 -1 2 -1 -1 -1 -1

// Sample Output 1 :

// true

// Sample Input 2 :

// 5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

// Sample Output 2 :

// false


/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<climits>
#include<queue>
bool isbst(BinaryTreeNode<int>* root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data>max || root->data<min){
        return false;
    }
    bool leftCheck = isbst(root->left, min, root->data-1);
    bool rightCheck = isbst(root->right, root->data, max);
    
    return leftCheck&&rightCheck;
}


bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        return true;
    }
    int minimum = INT_MIN;
    int maximum = INT_MAX;
    
    return isbst(root, minimum, maximum);
//     bool leftCheck = isBST(root->left);
//     bool rightCheck = isBST(root->right);
//     bool check1 = true;
//     if(root->left){
//         if(root->data<root->left->data){
//             check1 = false;
//         }
//     }
//     bool check2 = true;
//     if(root->right){
//         if(root->data>root->right->data){
//             check2 = false;
//         }
//     }
//     return leftCheck && rightCheck && check1 && check2;
    
}
