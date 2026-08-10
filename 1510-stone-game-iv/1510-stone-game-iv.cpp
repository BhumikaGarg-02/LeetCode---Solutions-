
class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] stores if the player whose turn it is with 'i' stones will win
        std::vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                // If removing k*k leaves a losing state for the next player
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Current player wins, no need to check further
                }
            }
        }

        return dp[n];
    }
};