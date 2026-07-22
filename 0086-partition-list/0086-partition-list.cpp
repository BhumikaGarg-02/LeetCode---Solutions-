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
    ListNode* partition(ListNode* head, int x) {
        if (head==NULL || head->next==NULL){return head;}
        ListNode* less=new ListNode(-1);
        ListNode* l=less;
        ListNode* greater=new ListNode(-1);
        ListNode* g=greater;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(temp->val<x){
                l->next=temp;
                l=temp;
            }
            else{
                g->next=temp;
                g=temp;
            }
            temp=temp->next;
        }
        l->next=greater->next;
        g->next=nullptr;
        ListNode* result=less->next;
        delete less;
        delete greater;
        return result;
    }
};
void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}