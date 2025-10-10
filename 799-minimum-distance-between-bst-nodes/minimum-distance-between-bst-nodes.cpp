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
    int minDiffInBST(TreeNode* root) {
        vector<int> data;
        trav(root,&data);
        int diff = data[1] - data[0];
        for(int i=1;i<data.size()-1;i++){
            int temp = data[i+1] - data[i];
            if(temp < diff) diff = temp;
        }
        return diff;
    }
    void trav(TreeNode* root,vector<int>* data){
        if(root == nullptr) return;
        trav(root->left,data);
        data->push_back(root->val);
        trav(root->right,data);
    }
};