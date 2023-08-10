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
    int dfs(TreeNode* root,int& maxDia){
        if(!root)return 0;

        int left=dfs(root->left,maxDia);
        int right=dfs(root->right,maxDia);
        maxDia=max(left+right,maxDia);

        return (1+max(left,right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia=0;
        dfs(root,maxDia);
        return maxDia;
    }
};