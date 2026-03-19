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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        ListNode* temp = head;
        vector<int> val;
        while(temp!=nullptr){
            val.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int n=val.size();
        k=k%n;
        reverse(val.begin(),val.end());
        reverse(val.begin(),val.begin()+k);
        reverse(val.begin()+k,val.end());
        int i=0;
        while(temp!=nullptr){
            temp->val=val[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};