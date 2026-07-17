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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){return NULL;}
        if(head->next==NULL){
            if(n==1)return NULL;
            else{return head;}
        }
        int cnt2=1;
        int cnt1=1;
        ListNode* current=head;
        ListNode* nth=head;       
        ListNode* prev=NULL;       
        while(current->next!=NULL){
            if(cnt2-cnt1!=n-1){
                cnt2++;
                current=current->next;
            }
            else if(current->next!=NULL){
                prev=nth;
                nth=nth->next;
                cnt1++;
                current=current->next;
                cnt2++;
                }
        }
        if (prev == NULL) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        prev->next=nth->next;
        delete nth;

        return head;
    }
};