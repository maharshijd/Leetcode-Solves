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
    int getDecimalValue(ListNode* head) {
        vector<int> val;
        ListNode* temp = head;
        while(temp!=nullptr){
            val.push_back(temp->val);
            temp=temp->next;
        }
        reverse(val.begin(),val.end());
        int sum=0;
        for(int i=0;i<val.size();i++){
            sum+=val[i]*pow(2,i);
        }
        return sum;
    }
};