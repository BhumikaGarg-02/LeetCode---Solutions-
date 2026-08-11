class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        // Step 1: Find the sum of the longest sequential prefix
        int prefixSum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break; // Sequential chain broke
            }
        }
        
        // Step 2: Store all elements of nums in a hash set for O(1) lookups
        std::unordered_set<int> presentNums(nums.begin(), nums.end());
        
        // Step 3: Find the smallest integer x >= prefixSum missing from nums
        int x = prefixSum;
        while (presentNums.count(x)) {
            x++;
        }
        
        return x;
    }
};