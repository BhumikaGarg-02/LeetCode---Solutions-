class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max2=LLONG_MIN;
        long long max1=LLONG_MIN;
        long long max3=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max1){
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2 && max1!=nums[i]){max3=max2;
            max2=nums[i];}
            else if(nums[i]>max3 && nums[i]!=max2 && nums[i]!=max1){
                max3=nums[i];
            }
        }
        if(max3==LLONG_MIN){return max1;}
        return max3;
    }
};
static const bool __boost = []() { std::cin.tie(nullptr); std::cout.tie(nullptr); return std::ios_base::sync_with_stdio(false); }(); const size_t BUFFER_SIZE = 0x3000000; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {} 