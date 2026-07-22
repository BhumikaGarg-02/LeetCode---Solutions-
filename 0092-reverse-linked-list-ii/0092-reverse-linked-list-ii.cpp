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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* leftnode=nullptr;
        ListNode* rightnode=nullptr;
        int cnt=1;
        while(cnt!=left){
           prev=temp;
           temp=temp->next;
           cnt++;
        }
        leftnode=temp;
        while(cnt!=right){
            temp=temp->next;
            cnt++;
        }
        rightnode=temp;
        ListNode* next=rightnode->next;
        rightnode->next=nullptr;
        ListNode* revhead=reverseList(leftnode);
         leftnode->next=next;
        if(prev)prev->next=revhead;
        else head=revhead;
        return head;
    }
};