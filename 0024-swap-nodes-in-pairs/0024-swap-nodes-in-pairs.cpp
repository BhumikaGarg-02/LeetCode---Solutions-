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