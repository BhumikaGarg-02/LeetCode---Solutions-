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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i=list1;
        ListNode* j=list2;
        ListNode* prev=NULL;
        while(i!=NULL && j!=NULL){
            if(i->val<=j->val){
                prev=i;
                i=i->next;
            }
            else{
                ListNode* temp=new ListNode(j->val,i);
                if(prev!=NULL){
                    prev->next=temp;
                    prev=temp;
                }
                else{
                    list1=temp;
                    i=temp;
                }
                 j=j->next;
            }
        }
        if (j != NULL) {
            if (prev != NULL) {
                prev->next = j;
            } else {
                list1 = j; // If list1 was empty, list2 becomes the head
            }
        }
        return list1;
    }
};