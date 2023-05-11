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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        deque<TreeNode*> level;
        level.push_front(root);
        bool forwardPass=true;
        while(level.size()>0){
            int n=level.size();
            vector<int> new_level;
            for(int i=0;i<n;i++){
                if(forwardPass){
                    TreeNode* node=level.front();
                    new_level.emplace_back(node->val);
                    if(node->left)level.push_back(node->left);
                    if(node->right)level.push_back(node->right);
                    level.pop_front();
                }else{
                    TreeNode* node=level.back();
                    new_level.emplace_back(node->val);
                    if(node->right)level.push_front(node->right);
                    if(node->left)level.push_front(node->left);
                    level.pop_back();
                }

            }
            ans.emplace_back(new_level);
            forwardPass=forwardPass?false:true;
        }
        return ans;
    }
};