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
    int maxheight(TreeNode* root){
        if(root==NULL)return 0;
        
        int left=maxheight(root->left);
        int right = maxheight(root->right);
        
        return max(left,right)+1;
    }
public:
    int maxDepth(TreeNode* root) {
       return  maxheight(root);
    }
};