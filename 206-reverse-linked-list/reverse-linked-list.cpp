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
    ListNode* reverseList(ListNode* head) {
        vector<int> data;
        struct ListNode* temp = head;
        while(temp!=nullptr){
            data.push_back(temp->val);
            temp = temp->next;
        }
        temp=head;
        int i=0,j=data.size()-1;
        while(i<=j){
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
            j--;
        }
        i=0;
        while(temp!=nullptr){
            temp->val=data[i];
            temp = temp->next;
            i++;
        }
        return head;

    }
};