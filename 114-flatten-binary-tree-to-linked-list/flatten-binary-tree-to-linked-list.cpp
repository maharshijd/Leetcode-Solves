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
    void flatten(TreeNode* root) {
        vector<int> val;
        preOrder(root,val);

        TreeNode* dummy = new TreeNode(-1);
        TreeNode* curr = dummy;

        for(int i = 0; i < val.size(); i++){
            curr->right = new TreeNode(val[i]);
            curr = curr->right;
        }
        TreeNode* temp = dummy->right;
        TreeNode* original = root;
        while (temp) {
            original->val = temp->val;
            original->left = nullptr;
            if (temp->right) {
                original->right = new TreeNode(0);
                original = original->right;
            }

            temp = temp->right;
        }
    }

    void preOrder(TreeNode* root, vector<int>& result){
        if(root == nullptr) return;
        result.push_back(root->val);
        preOrder(root->left,result);
        preOrder(root->right,result);
    }
};