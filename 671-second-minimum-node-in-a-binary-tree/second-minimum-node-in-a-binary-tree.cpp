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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> values;
        inOrder(root,values);
        sort(values.begin(),values.end());
        vector<int> ans;
        int j=0;
        ans.push_back(values[0]);
        for(int i=1;i<values.size();i++)
        {
            if(values[i] > ans[j]){
                ans.push_back(values[i]);
                j++;
            }
        }
        if(ans.size()>=2) return ans[1];
        else return -1;    
    }
    void inOrder(TreeNode* root, vector<int>& values){
        if(root == nullptr) return;
        inOrder(root->left,values);
        values.push_back(root->val);
        inOrder(root->right,values);
    }
};