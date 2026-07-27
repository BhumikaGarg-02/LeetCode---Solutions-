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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* anshead=new  ListNode(-1);
         ListNode* ans=anshead;
         ListNode* t1=reverseList(l1);
         ListNode* t2=reverseList(l2);
         int carry=0;
          while(t1!=nullptr && t2!=nullptr){
            ListNode* sum=new ListNode(t1->val+t2->val+carry);
            if(sum->val<10)carry=0;
            else{
                carry=sum->val/10;
                sum->val=(sum->val)%10;
            }
            ans->next=sum;
            ans=sum;
            t1=t1->next;
            t2=t2->next;
          }
          while(t1){
             ListNode* sum=new ListNode(t1->val+carry);
             if(sum->val<10)carry=0;
            else{
                carry=sum->val/10;
                sum->val=(sum->val)%10;
            }
            ans->next=sum;
            ans=sum;
            t1=t1->next;
          }
          while(t2){
             ListNode* sum=new ListNode(t2->val+carry);
             if(sum->val<10)carry=0;
            else{
                carry=1;
                sum->val=(sum->val)%10;
            }
            ans->next=sum;
            ans=sum;
            t2=t2->next;
          }
          if(carry==1){
             ListNode* node = new ListNode(1);
             ans->next=node;
          }
          anshead=anshead->next;
          anshead=reverseList(anshead);
          return anshead;
    }
};