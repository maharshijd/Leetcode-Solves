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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> Val;
        ListNode* temp = head;
        int tempSum=0;
        while(temp!=nullptr){
            if(temp->val != 0){
                tempSum+=temp->val;
            }
            else{
                if(tempSum!=0) Val.push_back(tempSum);
                tempSum=0;
            }
            temp=temp->next;
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        for(int i=0;i<Val.size();i++){
            curr->next = new ListNode(Val[i]);
            curr=curr->next;
        }   
        return dummy->next;
    }
};