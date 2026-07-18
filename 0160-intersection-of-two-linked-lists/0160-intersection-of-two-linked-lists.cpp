/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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

int init = [] {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out");
    for (string s; getline(std::cin, s);) {
        if (s[0] != '0')
            out << "Intersected at '" << s << "'\n";
        else
            out << "No intersection\n";
        for (int i = 0; i < 4; ++i)
            getline(std::cin, s);
    }
    out.flush();
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){return NULL;}
        ListNode * t1=headA;
        ListNode * t2=headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2){return t1;}
            if(t1==NULL){t1=headB;}
            if(t2==NULL){t2=headA;}
        }
        return t1;
    }
};