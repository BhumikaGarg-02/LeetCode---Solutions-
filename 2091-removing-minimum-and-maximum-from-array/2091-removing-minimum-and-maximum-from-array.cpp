class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int minIdx = 0;
        int maxIdx = 0;

        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[minIdx]) minIdx = k;
            if (nums[k] > nums[maxIdx]) maxIdx = k;
        }

        int i = std::min(minIdx, maxIdx);
        int j = std::max(minIdx, maxIdx);

        // 1. Both from front
        int removeBothFront = j + 1;
        
        // 2. Both from back
        int removeBothBack = n - i;
        
        // 3. One from front, one from back
        int removeFrontAndBack = (i + 1) + (n - j);

        return std::min({removeBothFront, removeBothBack, removeFrontAndBack});
    }
};