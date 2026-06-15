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
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        vector<int> data;
        ListNode* temp = head;
        while (temp != nullptr) {
            data.push_back(temp->val);
            temp = temp->next;
        }
        int low = 0;
        int high = data.size() - 1;
        vector<int> new_data;
        while (low < high) {
            new_data.push_back(data[low++]);
            new_data.push_back(data[high--]);
        }
        if (low == high) {
            new_data.push_back(data[low]);
        }
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = new_data[i];
            temp = temp->next;
            i++;
        }
    }
};