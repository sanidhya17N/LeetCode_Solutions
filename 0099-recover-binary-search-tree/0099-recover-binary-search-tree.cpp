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
    TreeNode* first=NULL;
    TreeNode* mid=NULL;
    TreeNode* last=NULL;
    TreeNode* prev=NULL;
  
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);

        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first=prev;
                mid=root;
            }else{
                last=root;
            }
        }

        prev=root;



        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
      prev=new TreeNode(INT_MIN);  
      inorder(root);
      if(last!=NULL){
          swap(last->val,first->val);
      }else{
          swap(first->val,mid->val);
      }

    }
};