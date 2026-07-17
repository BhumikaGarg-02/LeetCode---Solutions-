class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int cnt=0;
        for(int j=0;j<=n;j++){
            vector<int>mpp(26,0);
            for(int i=j;i<n;i++){
                mpp[s[i]-'a']++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(int k=0;k<=25;k++){
                    if(mpp[k]>0){
                        maxi=max(maxi,mpp[k]);
                        mini=min(mini,mpp[k]);
                    }
                }
                cnt+=(maxi-mini);
            }
        }
        return cnt;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}