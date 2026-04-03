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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        int len = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        temp = head;
        int mid = len/2;
        for(int i=0;i<mid-1;i++){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        return head;

    }
};