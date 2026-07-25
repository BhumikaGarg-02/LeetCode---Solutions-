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
        if(head==NULL || head->next==NULL){return head;}
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
    void reorderList(ListNode* head) {
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
           fast=fast->next->next;
           slow=slow->next;
        }
        ListNode* head2=reverseList(slow->next);
        slow->next=nullptr;
        ListNode* head1=head;
        ListNode* prev1=nullptr;
        ListNode* prev2=nullptr;
        while(head1!=nullptr && head2!=nullptr){
            prev1=head1;
            head1=head1->next;
            prev2=head2;
            head2=head2->next;
            prev1->next=prev2;
            prev2->next=head1;
        }
    }
};