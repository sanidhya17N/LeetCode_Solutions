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
    int maxDepth(TreeNode* root) {
        // if(!root)return 0;
        // int left=maxDepth(root->left);
        // int right=maxDepth(root->right);
        // return max(left,right)+1;
        int ans=0;
        if(root==nullptr)return ans;
        queue<TreeNode*> level;
        level.push(root);
        while(level.size()>0){
            ans++;
            int n=level.size();
            for(int i=0;i<n;i++){
                TreeNode* node=level.front();
                if(node->left)level.push(node->left);
                if(node->right)level.push(node->right);
                level.pop();
            }
        }
        return ans;

    }
};