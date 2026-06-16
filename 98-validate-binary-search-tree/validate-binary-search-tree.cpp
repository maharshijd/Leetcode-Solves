/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> data;
        inOrder(root, data);
        for (int i = 1; i < data.size(); i++) {
            if (data[i] > data[i - 1])
                continue;
            else
                return false;
        }
        return true;
    }
    void inOrder(TreeNode* root, vector<int>& data) {
        if (!root)
            return;
        inOrder(root->left, data);
        data.push_back(root->val);
        inOrder(root->right, data);
        return;
    }
};