class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        
        // Step 1: Count character frequencies
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        char mid_char = 0;
        vector<int> pool(26, 0);

        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
            pool[i] = count[i] / 2;
        }

        // If more than 1 char has an odd frequency, a palindrome cannot be formed
        if (odd_count > (n % 2)) {
            return "";
        }

        int m = n / 2;

        // Step 2 & 3: Iterate through possible prefix match lengths `k` downwards
        for (int k = m; k >= 0; --k) {
            vector<int> current_pool = pool;
            bool can_match = true;
            string half = "";

            // Try to match target up to index k - 1
            for (int i = 0; i < k; ++i) {
                int c = target[i] - 'a';
                if (current_pool[c] > 0) {
                    current_pool[c]--;
                    half += target[i];
                } else {
                    can_match = false;
                    break;
                }
            }

            if (!can_match) continue; // If we can't form this prefix, try a shorter one

            if (k == m) {
                // Completely matched the first half of target
                string P = half;
                if (n % 2 != 0) {
                    P += mid_char;
                }
                string rev = half;
                reverse(rev.begin(), rev.end());
                P += rev;
                
                // If it is strictly greater, then it is our answer
                if (P > target) return P;
            } else {
                // Look for the smallest available char strictly greater than target[k]
                int req_min = target[k] - 'a' + 1;
                int chosen = -1;
                for (int c = req_min; c < 26; ++c) {
                    if (current_pool[c] > 0) {
                        chosen = c;
                        break;
                    }
                }

                if (chosen != -1) {
                    // Place the chosen character
                    half += (char)('a' + chosen);
                    current_pool[chosen]--;

                    // Append the rest in sorted order to ensure lexicographically smallest
                    for (int c = 0; c < 26; ++c) {
                        half.append(current_pool[c], 'a' + c);
                    }

                    // Build and return the final strictly greater Palindrome
                    string P = half;
                    if (n % 2 != 0) {
                        P += mid_char;
                    }
                    string rev = half;
                    reverse(rev.begin(), rev.end());
                    P += rev;
                    
                    return P;
                }
            }
        }

        // Step 4: If no valid configuration was found, return an empty string
        return "";
    }
};