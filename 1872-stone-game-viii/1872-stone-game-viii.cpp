class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Compute prefix sums
        std::vector<long long> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        
        // Step 2: Dynamic programming from right to left
        // Base case: at index n - 2, the only choice is to take all remaining stones.
        long long maxDiff = prefix[n - 1];
        
        for (int i = n - 2; i >= 1; --i) {
            maxDiff = std::max(maxDiff, prefix[i] - maxDiff);
        }
        
        return maxDiff;
    }
};