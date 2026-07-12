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
private:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){return head ;}
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next=head->next;
        while(temp!=NULL){
            temp->next=prev;
            prev=temp;
            temp=next;
            if(next!=NULL){next=next->next;}
        }
        head=prev;
        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){return true ;}
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* sechalf=reverseList(slow);
        ListNode* i=head;
        ListNode* j=sechalf;
        while(i!=NULL && j!=NULL){
            if(i->val!=j->val){return false;}
            else{
                i=i->next;
                j=j->next;
            }
        }
        return true ;
    }
};