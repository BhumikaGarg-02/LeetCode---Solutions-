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
        int i=2;
        int diff=INT_MAX;
        int el=-1;
        int mini=-1;
        while(next!=nullptr){
            if(temp->val>next->val && temp->val>prev->val){
                if(el==-1)mini=i;
                if(el!=-1)diff=min(diff,i-el);
                el=i;
                }
            else if(temp->val<next->val && temp->val<prev->val){
                if(el==-1)mini=i;
                if(el!=-1)diff=min(diff,i-el);
                el=i;
                }
            i++;
            prev=temp;
            temp=next;
            next=next->next;
        }
        if(el==-1 || mini==el)return{-1,-1};
        return{diff,el-mini};
    }
};