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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){return head;}
        int cnt=1;
        int a=0;
        ListNode* temp=head;
        ListNode* start=NULL;
        ListNode* prev=NULL;
        while(temp!=NULL){
            if(cnt!=k){
                if(cnt==1){start=temp;}
                temp=temp->next;
                cnt++;
            }
            else{
                ListNode* end=temp;
                temp=temp->next;
                end->next=NULL;
                ListNode* rev_head=reverseList(start);
                if(a==0){
                    head=rev_head;
                    a=1;
                }
                if(prev)prev->next=rev_head;
                prev=start;
                start->next=temp;
                cnt=1;
            }
        }
        return head;
    }
};