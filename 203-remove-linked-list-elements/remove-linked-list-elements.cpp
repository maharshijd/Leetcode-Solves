class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;

        while (head != nullptr && head->val == val) {
            ListNode* delNode = head;
            head = head->next;
            delete delNode;
        }

        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
            } else {
                temp = temp->next;
            }
        }
        
        return head;
    }
};
