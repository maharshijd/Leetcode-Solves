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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> data;
        struct ListNode* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (pos >= left && pos <= right) {
                data.push_back(temp->val);
            }
            temp = temp->next;
            pos++;
        }
        int i=0,j= data.size()-1;
        while(i<=j){
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            i++;
            j--;

        }
        temp = head;
        pos = 1;
        i = 0;
        while (temp != nullptr) {
            if (pos >= left && pos <= right) {
                temp->val = data[i++];
            }
            temp = temp->next;
            pos++;
        }
        return head;
    }
};