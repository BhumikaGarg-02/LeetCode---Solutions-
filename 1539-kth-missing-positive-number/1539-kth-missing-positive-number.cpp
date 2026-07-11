class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>miss;
        int n=arr.size();
        for(int i=1;i<arr[0];i++){
            miss.push_back(i);
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]!=arr[i]+1){
                for(int j=arr[i]+1;j<arr[i+1];j++){
                    miss.push_back(j);
                }
            }
        }
        while(miss.size()<k){
            if(!miss.empty()){
                int i=max(arr.back(),miss.back());
                miss.push_back(i+1);
            }
            else{
                miss.push_back(arr.back()+1);
            }
        }
        return miss[k-1] ;
    }
};
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}