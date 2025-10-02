/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        struct ListNode* fast = head;
        struct ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                struct ListNode* entry = head;
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            };
        }
        return nullptr;
    }
};