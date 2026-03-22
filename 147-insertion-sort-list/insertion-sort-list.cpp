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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> val;
        ListNode* temp = head;
        while (temp != nullptr) {
            val.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int n=val.size();
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            for (; j >= 0; j--) {
                if (val[j + 1] < val[j]) {
                    int tempVal = val[j];
                    val[j] = val[j+1];
                    val[j+1] = tempVal;
                } else {
                    break;
                }
            }
        }
        int i=0;
        while(temp!=nullptr){
            temp->val=val[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};