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
    int getDecimalValue(ListNode* head) {
        if (head==NULL){return 0;}
        ListNode* temp=head;
        int res=0;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            res=res+(temp->val*pow(2,len-1));
            len--;
            temp=temp->next;
        }
        return res;
    }
};