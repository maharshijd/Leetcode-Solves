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
    vector<int> inorderTraversal(TreeNode* root) {  
        vector<int> data;
        trav(root,&data);
        return data;        
    }
    void trav(TreeNode* root,vector<int>* data){
        if(root == nullptr) return;
        trav(root->left,data);
        data->push_back(root->val);
        trav(root->right,data);
    }
};