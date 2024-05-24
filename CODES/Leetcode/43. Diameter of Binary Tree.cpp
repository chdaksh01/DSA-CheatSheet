// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// Two Approches:
// 1. O(N^2)
// 2. O(N)

//O(N^2)

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
    int height(TreeNode* node){
        if (node==NULL) {return 0;}
        else if (height(node->left)>height(node->right)) {return 1 + height(node->left);}
        else return 1 + height(node->right);
    }
    int max = 0;
    void func(TreeNode* node)
    {
        if (node==NULL) {return;}
        int h = height(node->left) + height(node->right);
        if (h > max) {max = h;}
        func(node->left);
        func(node->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        func(root);
        return max;
    }
};



//O(N)

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
    int mm = 0;
    int height(TreeNode* node){
        if (node==NULL) {return 0;}
        else{
            int lh = height(node->left);
            int rh = height(node->right);
            mm = max(mm, lh + rh);
            if (lh>rh) {return 1 + lh;}
            else return 1 + rh;
        }
    }
   
    int diameterOfBinaryTree(TreeNode* root) {
        int h = height(root);
        // func(root);
        return mm;
    }
};
