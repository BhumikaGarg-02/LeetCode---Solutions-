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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* prev= head;
        while(temp!=NULL){
            while( temp!=NULL && temp->val==prev->val){
                temp=temp->next;
            }
            if(temp==NULL){
                prev->next=NULL;
                return head;
            }
            prev->next=temp;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};