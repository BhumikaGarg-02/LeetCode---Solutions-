class Solution {
    // Helper to calculate Least Common Multiple (LCM)
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / std::gcd(a, b)) * b;
    }

    // Counts how many values <= target are divisible by at least one coin
    long long countMultiples(long long target, const vector<int>& coins) {
        long long count = 0;
        int n = coins.size();

        // Iterate through all non-empty subsets of coins
        for (int i = 1; i < (1 << n); ++i) {
            long long currentLcm = 1;
            int setBits = 0;

            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    setBits++;
                    currentLcm = lcm(currentLcm, coins[j]);
                    // If LCM exceeds target, its contribution to count is 0
                    if (currentLcm > target) break;
                }
            }

            if (currentLcm <= target) {
                if (setBits % 2 == 1) {
                    count += target / currentLcm;
                } else {
                    count -= target / currentLcm;
                }
            }
        }
        return count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        // Remove redundant coins (e.g., if we have 2, then 4 is redundant)
        sort(coins.begin(), coins.end());
        vector<int> filteredCoins;
        for (int c : coins) {
            bool redundant = false;
            for (int existing : filteredCoins) {
                if (c % existing == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                filteredCoins.push_back(c);
            }
        }

        // Binary Search Range
        long long low = 1;
        long long high = (long long)filteredCoins[0] * k;
        long long result = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countMultiples(mid, filteredCoins) >= k) {
                result = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1; // Need a larger amount
            }
        }

        return result;
    }
};