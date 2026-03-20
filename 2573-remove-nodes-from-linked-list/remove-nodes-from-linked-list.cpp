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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> val;
        ListNode* temp = head;

        while(temp != nullptr){
            val.push_back(temp->val);
            temp = temp->next;
        }

        int n = val.size();
        vector<int> isValid(n);

        int maxi = val[n-1];
        isValid[n-1] = 1;

        for(int i = n-2; i >= 0; i--){
            if(val[i] < maxi){
                isValid[i] = 0;
            } else {
                isValid[i] = 1;
                maxi = val[i];
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int i = 0; i < n; i++){
            if(isValid[i] == 1){
                curr->next = new ListNode(val[i]);
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};