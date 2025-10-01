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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        struct ListNode* temp = head;
        vector<int> reps;
        while (temp != nullptr && temp->next != nullptr) {
            struct ListNode* dupli = temp->next;
            if (dupli->val == temp->val) {
                reps.push_back(dupli->val);
                temp->next = dupli->next;
                delete dupli;
            } else {
                temp = temp->next;
            }
        }
        while (head != nullptr) {
            bool found = false;
            for (int i = 0; i < reps.size(); i++) {
                if (head->val == reps[i]) {
                    found = true;
                    break;
                }
            }
            if (!found)
                break;

            ListNode* del = head;
            head = head->next;
            delete del;
        }
        if (head == nullptr)
            return nullptr;
        temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            bool found = false;
            for (int i = 0; i < reps.size(); i++) {
                if (temp->next->val == reps[i]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ListNode* dupli = temp->next;
                temp->next = dupli->next;
                delete dupli;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};