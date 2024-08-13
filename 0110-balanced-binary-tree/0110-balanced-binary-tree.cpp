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
    int isbalance(TreeNode* root){
        if(root==NULL)return 0;
        
        int left= isbalance(root->left);
        int right= isbalance(root->right);
        
        if(left==-1 || right==-1)return -1;
        if(abs(left-right)>1)return -1;
        
        return 1+ max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(isbalance(root)!=-1)return true;
        else return false;
    }
};