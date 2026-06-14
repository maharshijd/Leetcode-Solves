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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr) return nullptr;
        vector<int> data;
        inOrder(root,data);
        TreeNode* dummy = new TreeNode();
        TreeNode* temp = new TreeNode(data[0]);
        dummy->right = temp;
        for(int i=1;i<data.size();i++){
            temp->right = new TreeNode(data[i]);
            temp = temp->right;
        }
        return dummy->right;
    }
    void inOrder(TreeNode* root, vector<int>& data){
        if(root == nullptr) return;
        inOrder(root->left,data);
        data.push_back(root->val);
        inOrder(root->right,data);
        return;
    }
    
};