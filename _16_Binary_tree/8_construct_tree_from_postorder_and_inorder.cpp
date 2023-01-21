//  Construct Tree from Postorder and Inorder
// Send Feedback
// For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, 
// create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
// Note:

// Assume that the Binary Tree contains only unique elements. 

// Input Format:

// The first line of input contains an integer N denoting the size of the list/array. It can also be said that N 
// is the total number of nodes the binary tree would have.

// The second line of input contains N integers, all separated by a single space. 
// It represents the Postorder-traversal of the binary tree.

// The third line of input contains N integers, all separated by a single space. 
// It represents the inorder-traversal of the binary tree.

// Output Format:

// The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
// Elements on every level will be printed in a linear fashion. A single space will separate them.

// Constraints:

// 1 <= N <= 10^4
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec

// Sample Input 1:

// 7
// 4 5 2 6 7 3 1 
// 4 2 5 1 6 3 7 

// Sample Output 1:

// 1 
// 2 3 
// 4 5 6 7 

// Sample Input 2:

// 6
// 2 9 3 6 10 5 
// 2 6 3 9 5 10 

// Sample Output 2:

// 5 
// 6 10 
// 2 3 
// 9 

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    if(inLength==0||postLength==0){
        return NULL;
    }
    int rootData = postorder[postLength-1];
    BinaryTreeNode<int>* root =new BinaryTreeNode<int> (rootData);
    
    int k = 0;
    for(int i=0;i<inLength;i++){
        if(inorder[i]==rootData){
            break;
        }
        k++;
    }
    
    int m = inLength-k-1;
    
    root->left = buildTree(postorder, k, inorder, k);
    root->right = buildTree(postorder+k, m, inorder+k+1, m );
    
    return root;
}
