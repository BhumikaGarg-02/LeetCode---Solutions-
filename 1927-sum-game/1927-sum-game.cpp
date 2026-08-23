class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        // Count sum and '?' for the first half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                q1++;
            } else {
                sum1 += (num[i] - '0');
            }
        }

        // Count sum and '?' for the second half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                q2++;
            } else {
                sum2 += (num[i] - '0');
            }
        }

        // Bob wins if the sum difference balances out the remaining '?' pairs.
        // Sum condition: (sum1 - sum2) + (q1 - q2) / 2 * 9 == 0
        // If this holds true, Bob wins (return false for Alice win).
        // Otherwise, Alice wins (return true).
        return (sum1 - sum2) * 2 != (q2 - q1) * 9;
    }
};