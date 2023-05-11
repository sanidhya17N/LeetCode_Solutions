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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<TreeNode* > level;
        level.push(root);
        while(level.size()>0){
            int n=level.size();
            vector<int> new_level;
            for(int i=0;i<n;i++){
                TreeNode* node=level.front();
                new_level.emplace_back(node->val);
                if(node->left)level.push(node->left);
                if(node->right)level.push(node->right);
                level.pop();
            }

            ans.emplace_back(new_level);
        }
        return ans;
    }
};