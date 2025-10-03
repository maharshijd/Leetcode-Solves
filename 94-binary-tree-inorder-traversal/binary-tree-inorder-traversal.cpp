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
        vector<int> trav;
        inOrder(root,trav);

        return trav;
    }
    void inOrder(TreeNode* root,vector<int>& trav){
        if(root == nullptr) return;
        inOrder(root->left,trav);
        trav.push_back(root->val);
        inOrder(root->right,trav);
    }
};