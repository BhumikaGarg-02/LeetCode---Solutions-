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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){return head;}
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int r=k%len;
        if(r==0){return head;}
        head=reverseList(head);
        int cnt=1;
        temp=head;
        while(cnt!=r){
            temp=temp->next;
            cnt++;
        }
        ListNode* nextnode=temp->next;
        temp->next=NULL;
        ListNode* rev_head1=reverseList(head);
        ListNode* rev_head2=reverseList(nextnode);
        head->next=rev_head2;
        return rev_head1;
    }
};