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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> val1;
        vector<int> val2;
        ListNode* temp;
        temp = l1;
        while (temp != nullptr) {
            val1.push_back(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while (temp != nullptr) {
            val2.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> sum;
        int m = val1.size();
        int n = val2.size();
        int minSize = min(m, n);
        int carry = 0;
        for (int i = 0; i < minSize; i++) {
            int val = val1[m - 1 - i] + val2[n - 1 - i];
            if (carry == 1) {
                val += 1;
            }
            carry = val / 10;
            sum.push_back(val % 10);
        }
        while (m > minSize) {
            int val = val1[m - minSize - 1] + carry;
            carry = val / 10;
            sum.push_back(val % 10);
            m--;
        }

        while (n > minSize) {
            int val = val2[n - minSize - 1] + carry;
            carry = val / 10;
            sum.push_back(val % 10);
            n--;
        }

        if (carry)
            sum.push_back(carry);
        reverse(sum.begin(), sum.end());
        ListNode* dummy = new ListNode();
        temp = dummy;
        for (int i = 0; i < sum.size(); i++) {
            temp->next = new ListNode(sum[i]);
            temp = temp->next;
        }
        return dummy->next;
    }
};