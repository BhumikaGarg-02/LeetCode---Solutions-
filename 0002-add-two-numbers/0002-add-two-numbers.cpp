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
 #pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

static constexpr size_t mxal = alignof(max_align_t);
alignas(mxal) static unsigned char buf[256 * 1024 * 1024];
static size_t pos = 0;

void* operator new(size_t sz) {
    size_t pad = (mxal - (pos % mxal)) % mxal;
    pos += pad + sz;
    return (void*)(&buf[pos - sz]);
}

void* operator new[](size_t sz) { return operator new(sz); }

void operator delete(void*) noexcept {}
void operator delete[](void*) noexcept {}
void operator delete(void*, size_t) noexcept {}
void operator delete[](void*, size_t) noexcept {}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* anshead=new  ListNode(-1);
         ListNode* ans=anshead;
          ListNode*t1=l1;
          ListNode*t2=l2;
          int carry=0;
          while(t1!=NULL && t2!=NULL){
             ListNode* sum=new  ListNode(t1->val+t2->val+carry);
             if(sum->val<10){
                carry=0;
             }
             else{
                sum->val=(sum->val)%10;
                carry=1;
             }
             ans->next=sum;
             ans=sum;
             t1=t1->next;
             t2=t2->next;
          }
          if(carry==1 && t1==NULL && t2==NULL){
                ListNode* s=new ListNode(1);
                ans->next=s;
                return anshead->next;
            }
          else if(carry==0){
            if(t1){ans->next=t1;}
            else{ans->next=t2;}
            return anshead->next;
          }
          else if(carry==1){
            if(t1){
                while(t1!=NULL){
                    ListNode* s=new ListNode(t1->val+carry);
                    if(s->val>=10){
                        s->val=(s->val)%10;
                        carry=1;
                    }
                    else{
                        carry=0;}
                    ans->next=s;
                    ans=s;
                    t1=t1->next;
                }
            }
            else if(t2){
                while(t2!=NULL){
                    ListNode* s=new ListNode(t2->val+carry);
                    if(s->val>=10){
                        s->val=(s->val)%10;
                        carry=1;
                    }
                    else{
                        carry=0;}
                    ans->next=s;
                    ans=s;
                    t2=t2->next;
                }
            }
          }
            if(carry==1 && t1==NULL && t2==NULL){
                ListNode* s=new ListNode(1);
                ans->next=s;
            }
            return anshead->next;
          }
};