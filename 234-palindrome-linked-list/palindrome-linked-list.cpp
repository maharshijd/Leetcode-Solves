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
    bool isPalindrome(ListNode* head) {
        vector<int> data;
        struct ListNode* temp = head;
        while(temp != nullptr){
            data.push_back(temp->val);
            temp = temp->next;
        }
        int i=0,j=data.size()-1;
        vector<int> data1 = data;
        while(i<=j){
            int temp = data1[i];
            data1[i] = data1[j];
            data1[j] = temp;
            i++;
            j--;
        }
        int flag =1;
        for(i=0;i<data.size();i++){
            if(data[i] == data1[i]){
                flag = 1;
            }
            else{
                flag = 0;
                break;
            } 
        }
        if(flag == 1) return true;
        else return false;
    }
};