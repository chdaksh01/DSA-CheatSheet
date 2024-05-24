//Given the root of a binary tree, invert the tree, and return its root.

      4
    /   \
   2     7
  / \   /  \
 1   3 6    9

      ||
      
      4
    /   \
   7     2
  / \   /  \
 9   6 3    1
        

// 2 ways - SAME T.C. -> O(N)

// 1. - MY
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void invert(TreeNode* node){
        if (node==NULL) {return;}
        TreeNode* ptr = node->left;
        node->left = node->right;
        node->right = ptr;
        invert(node->left);
        invert(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;

    }
};

// 2. - Another
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base Case
        if(root==NULL)
            return NULL;
        invertTree(root->left); //Call the left substree
        invertTree(root->right); //Call the right substree
        // Swap the nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root; // Return the root
    }
};
