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
 #pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return &BUFFER[pos - size];
}

void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}

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