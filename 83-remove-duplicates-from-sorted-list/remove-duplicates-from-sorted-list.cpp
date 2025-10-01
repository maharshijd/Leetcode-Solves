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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr||head->next == nullptr ){return head;}
        struct ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            struct ListNode* dupli = temp->next;
            if(dupli->val == temp->val){
                temp->next = dupli->next;
                delete dupli;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};