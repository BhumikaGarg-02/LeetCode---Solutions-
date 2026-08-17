class Solution {
private: 
    int memo[501][501];
    
    int solve(int i, int j, const vector<int>& pref, const vector<int>& stoneValue) {
        // Base case: only one stone left, no more score can be gained
        if (i == j) return 0;
        
        // Return cached result if already computed
        if (memo[i][j] != -1) return memo[i][j];
        
        int maxScore = 0;
        
        // Try all possible split points k
        for (int k = i; k < j; ++k) {
            int leftSum = pref[k + 1] - pref[i];
            int rightSum = pref[j + 1] - pref[k + 1];
            
            if (leftSum < rightSum) {
                // Bob throws right row, Alice keeps left row
                maxScore = max(maxScore, leftSum + solve(i, k, pref, stoneValue));
            } else if (leftSum > rightSum) {
                // Bob throws left row, Alice keeps right row
                maxScore = max(maxScore, rightSum + solve(k + 1, j, pref, stoneValue));
            } else {
                // Equal sums: Alice chooses the maximum path
                int takeLeft = leftSum + solve(i, k, pref, stoneValue);
                int takeRight = rightSum + solve(k + 1, j, pref, stoneValue);
                maxScore = max(maxScore, max(takeLeft, takeRight));
            }
        }
        
        return memo[i][j] = maxScore;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Compute prefix sums for O(1) range sum queries
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        
        // Initialize memoization table with -1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j] = -1;
            }
        }
        
        return solve(0, n - 1, pref, stoneValue);
    }
};