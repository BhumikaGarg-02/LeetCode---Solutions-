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
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL || head->next==NULL){return head;} 
       ListNode* prev=head;
       ListNode* temp=head->next;
       ListNode* nextlink=temp->next;
       ListNode* back=NULL;
       while(temp!=NULL){
        temp->next=prev;
        prev->next=nextlink;
        if(back){back->next=temp;}
        back=prev;
        if(prev==head){head=temp;}
        if(nextlink==NULL)break;
        prev=nextlink;
        if(prev)temp=prev->next;
        if(temp)nextlink=temp->next;
       }
       return head;
    }
};