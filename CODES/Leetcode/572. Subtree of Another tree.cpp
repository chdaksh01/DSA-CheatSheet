// It's IMPOSSIBLE (i think) to do this in one function itself

// ...bcz... Subtree ko recursion m daal diya matlab galti kardi!!

// Writing recursion is V critical here!!

// Did it in O(N^2) (or O(NM)). Can it be optimised?

// My Code
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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if (root==NULL || subRoot==NULL)
        {
            return root==NULL && subRoot==NULL;
        }
        else if (root->val == subRoot->val)
        {
            return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
        }
        else return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==NULL) {return false;}
        else if (isSame(root, subRoot)) {return true;}
        else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};


// SOME another submission on LEETCODE which I took help from:
class Solution {
public:
   
   bool isSametree(TreeNode* s, TreeNode* t){
       //if any of the tree is null then there is no need to compare 
       if(!s || !t){
           //if either of them are null both of them need to be null to be true
           return s==NULL && t==NULL;
       } //now since both are not null check if they have same value otherwise return false
       else if(s->val == t->val){
           //if value is same then check if both its left and right sub-tree are same          
           return isSametree(s->left,t->left) && isSametree(s->right,t->right);
       }
       else{
           return false;
       }
   }
   bool isSubtree(TreeNode* s, TreeNode* t) {
         if(!s){
             //if main tree is null then return false
             return false;
         }   
         else if(isSametree(s,t)){
             //check if s and t are same, if yes return true
             return true;
         }
         else{
             //if s and t are not same then pass left and right nodes, and check same for that nodes as well as its child nodes.
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
};
