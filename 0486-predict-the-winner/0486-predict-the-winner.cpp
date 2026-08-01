class Solution {
private:
    int memo[21][21]; // DP table to cache results

    int maxScoreDiff(std::vector<int>& nums, int i, int j) {
        // Base case: only one element left
        if (i == j) {
            return nums[i];
        }

        // Return cached result if already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Choice 1: Take nums[i]
        int takeLeft = nums[i] - maxScoreDiff(nums, i + 1, j);

        // Choice 2: Take nums[j]
        int takeRight = nums[j] - maxScoreDiff(nums, i, j - 1);

        // Cache and return the best outcome
        return memo[i][j] = std::max(takeLeft, takeRight);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize memoization table with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }

        // Player 1 wins if they can achieve a net difference >= 0
        return maxScoreDiff(nums, 0, n - 1) >= 0;
    }
};