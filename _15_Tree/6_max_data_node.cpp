// Code : Max data node
// Send Feedback
// Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
// Return null if tree is empty.
// Input format :

// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, 
// number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the 
// nodes of the tree is separated by space.

// Output Format :

// The first and only line of output contains the data of the node with largest data in the given tree.

// Constraints:

// Time Limit: 1 sec

// Sample Input 1:

// 10 3 20 30 40 2 40 50 0 0 0 0 

// Sample Output 1:

// 50



#include<queue>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return 0;
    }
    queue<TreeNode<int>*> q;
    
    q.push(root);
    TreeNode<int>* maxNode = root;
    
    while(!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        if(front->data>maxNode->data){
            maxNode = front;
        }
        for(int i=0;i<front->children.size();i++){
            q.push(front->children[i]);
        }
    }
    return maxNode;
}
