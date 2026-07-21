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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}
        ListNode* temp=head;
        ListNode* next=head->next;
        ListNode* unique=NULL;
        while(temp!=NULL && next!=NULL){
            if(next->val!=temp->val){
                unique=temp;
                temp=next;
                next=temp->next;
            }
            else{
                while(next!=NULL && next->val==temp->val){
                next=next->next;
                }
                if(temp==head && next==NULL){return NULL;}
                if(unique==NULL){head=next;}
                else unique->next=next;
                temp=next;
                if(next)next=next->next;
            }
        } 
          return head;  
    }
};