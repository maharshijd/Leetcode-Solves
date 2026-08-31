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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = curr;
        curr = curr->next;
        vector<int> critPoints;
        if(curr->next == nullptr) return {-1,-1};
        int idx = 1;
        while(curr->next!=nullptr){
            if(prev->val > curr->val && curr->next->val > curr->val) critPoints.push_back(idx);
            if(prev->val < curr->val && curr->next->val < curr->val) critPoints.push_back(idx);
            prev = curr;
            curr = curr->next;
            idx++;
        }
        if(critPoints.size() < 2) return {-1,-1};
        int maxDist = critPoints[critPoints.size()-1] - critPoints[0];
        int minDist = INT_MAX;
        for(int i =1;i<critPoints.size();i++){
            minDist = min(minDist,critPoints[i]-critPoints[i-1]);
        }
        return {minDist,maxDist};
    }
};