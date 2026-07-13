/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL ||head->next==NULL){return NULL;}
        ListNode * fast=head;
        ListNode * slow=head;
        int cnt=0;
        while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
                cnt++;
            if(fast==slow){break;}
        }
        if(fast!=slow){return NULL;}
        ListNode * s2=fast;
        ListNode * s1=head;
        while(s1!=s2){
            s1=s1->next;
            s2=s2->next;
        }
        return s2;
    }
};