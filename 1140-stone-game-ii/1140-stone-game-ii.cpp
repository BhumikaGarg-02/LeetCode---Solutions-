class Solution {
    int memo[101][101]; // Constraint: n <= 100
    vector<int> suffixSum;
    int n;

    int dp(int i, int M) {
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;
        for (int X = 1; X <= 2 * M; ++X) {
            int nextM = max(M, X);
            int currentStones = suffixSum[i] - dp(i + X, nextM);
            maxStones = max(maxStones, currentStones);
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.assign(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(int), -1);
        
        return dp(0, 1);
    }
};