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
    vector<int> addVectors(vector<int> a, vector<int> b) {
        vector<int> result;

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i--];
            if (j >= 0)
                sum += b[j--];

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        vector<int> v2;
        vector<int> v3;
        ListNode* temp1 = l1;
        while (temp1 != nullptr) {
            v1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        reverse(v1.begin(), v1.end());
        ListNode* temp2 = l2;
        while (temp2 != nullptr) {
            v2.push_back(temp2->val);
            temp2 = temp2->next;
        }
        reverse(v2.begin(), v2.end());
        v3 = addVectors(v1,v2);
        reverse(v3.begin(),v3.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        for(int i =0;i<v3.size();i++){
            curr->next=new ListNode(v3[i]);
            curr=curr->next;
        }
        return dummy->next;

    }
};