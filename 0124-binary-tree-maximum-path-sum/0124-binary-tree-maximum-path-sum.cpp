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

    int postOrder(TreeNode* root,int& maxm){
        if(!root){
            return 0;
        }
        int left=max(0,postOrder(root->left,maxm));
        int right=max(0,postOrder(root->right,maxm));
        maxm=max(maxm,left+right+root->val);

        return max(root->val+right,root->val+left);
    }
    int maxPathSum(TreeNode* root) {
        int maxm=INT_MIN;
        postOrder(root,maxm);
        return maxm;
    }
};