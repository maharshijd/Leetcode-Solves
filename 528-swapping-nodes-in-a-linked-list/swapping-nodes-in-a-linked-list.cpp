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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> val;
        ListNode* temp = head;
        while(temp!=nullptr){
            val.push_back(temp->val);
            temp=temp->next;
        }
        int i=k-1,j=val.size()-k;
        int tempVal=val[i];
        val[i]=val[j];
        val[j]=tempVal;
        temp=head;
        i=0;
        while(temp!=nullptr){
            temp->val=val[i];
            i++;
            temp=temp->next;
        }
        return head;
        
    }
};