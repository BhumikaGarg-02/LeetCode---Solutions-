class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int h=0;
        int n=weights.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            h+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int l=maxi;
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            int cnt=0,sum=0;
            for(int i=0;i<n;i++){
                sum+=weights[i];
                if(weights[i]>mid){
                    l=mid+1;
                    break;
                }
                if(sum>mid){
                    cnt++;
                    sum=weights[i];
                }
            }
            cnt++;
            if(cnt<=days){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
#pragma GCC optimize("Ofast")
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}