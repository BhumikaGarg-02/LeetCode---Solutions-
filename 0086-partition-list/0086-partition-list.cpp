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
    ListNode* partition(ListNode* head, int x) {
        if (head==NULL || head->next==NULL){return head;}
        ListNode* less=new ListNode(-1);
        ListNode* l=less;
        ListNode* greater=new ListNode(-1);
        ListNode* g=greater;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                l->next=temp;
                l=temp;
            }
            else{
                g->next=temp;
                g=temp;
            }
            temp=temp->next;
        }
        l->next=NULL;
        g->next=NULL;
        if(!greater->next){return less->next;}
        else if(!less->next){return greater->next;}
        else{
            l->next=greater->next;
            return less->next;
        }
    }
};