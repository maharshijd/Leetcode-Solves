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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int node_count = 0;
        if(head == nullptr) return head;
        ListNode* temp = head;
        while(temp!=nullptr){
            node_count++;
            temp = temp->next;
        }
        if(n==node_count) return head->next;
        temp = head;
        for(int i=0;i<(node_count-n-1);i++) temp=temp->next;
        temp->next=temp->next->next;
        return head;
    }
};