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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        while(temp!= nullptr && temp->next != nullptr){
            temp=swapVal(temp);
            temp= temp->next->next;
        }
        return head;
    }
    ListNode* swapVal(ListNode* node){
        ListNode* temp = node->next;
        int tempVal = node->val;
        node->val = temp->val;
        temp->val = tempVal;
        return node;
    }
};