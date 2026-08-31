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
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)return{-1,-1};
        ListNode* temp=head->next;
        ListNode* prev=head;
        ListNode* next=head->next->next;
        vector<int>ans;
        int i=2;
        while(next!=nullptr){
            if(temp->val>next->val && temp->val>prev->val)ans.push_back(i);
            else if(temp->val<next->val && temp->val<prev->val)ans.push_back(i);
            i++;
            prev=temp;
            temp=next;
            next=next->next;
        }
        if(ans.size()==0 || ans.size()==1)return{-1,-1};
        int diff=INT_MAX;
        int n=ans.size();
        for(int i=0;i<n-1;i++){
            diff=min(ans[i+1]-ans[i],diff);
        }
        int maxi=ans[n-1]-ans[0];
        return{diff,maxi};
    }
};