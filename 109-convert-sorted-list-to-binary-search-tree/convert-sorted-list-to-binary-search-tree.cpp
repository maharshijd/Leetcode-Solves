/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> nums;
        ListNode* temp=head;
        while(temp!=nullptr){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        return insert(nums,0,nums.size()-1);

    }
    TreeNode* insert(vector<int>& nums, int low, int high){
        if(low>high) return nullptr;
        int mid = low + (high-low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = insert(nums,low,mid-1);
        root->right = insert(nums,mid+1,high);
        return root;
    }
};