class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k equals the length of the array
        // Only 1 subarray of size k exists, so every element appears in exactly 1 subarray.
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }
        
        // Case 2: k == 1
        // An element appears in exactly 1 subarray iff its overall frequency is 1.
        if (k == 1) {
            std::unordered_map<int, int> freq;
            for (int num : nums) {
                freq[num]++;
            }
            int ans = -1;
            for (const auto& [num, count] : freq) {
                if (count == 1) {
                    ans = std::max(ans, num);
                }
            }
            return ans;
        }
        
        // Case 3: 1 < k < n
        // Only nums[0] and nums[n-1] can appear in exactly 1 subarray of size k.
        int ans = -1;
        
        // Check nums[0]
        if (std::count(nums.begin(), nums.end(), nums[0]) == 1) {
            ans = std::max(ans, nums[0]);
        }
        
        // Check nums[n-1]
        if (std::count(nums.begin(), nums.end(), nums[n-1]) == 1) {
            ans = std::max(ans, nums[n-1]);
        }
        
        return ans;
    }
    
};