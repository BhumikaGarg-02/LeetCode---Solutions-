class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // last[j] = maximum index in word1 to match word2[j] 
        // such that word2[j...m-1] can be matched exact (0 mismatches).
        vector<int> last(m, -1);
        
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            if (ptr >= 0) {
                last[j] = ptr;
                ptr--; // move left to ensure strictly smaller index for previous characters
            } else {
                break; // remaining suffix cannot be matched
            }
        }

        vector<int> result;
        bool mismatch_used = false;
        int w1_idx = 0;

        for (int i = 0; i < m; ++i) {
            bool found = false;
            
            while (w1_idx < n) {
                bool is_match = (word1[w1_idx] == word2[i]);
                bool can_finish_exact = (i == m - 1) || (last[i + 1] > w1_idx);

                if (is_match) {
                    // Match case: allowed if we can finish either with 0 mismatches 
                    // OR using our remaining mismatch allowance later.
                    if (can_finish_exact || !mismatch_used) {
                        result.push_back(w1_idx);
                        w1_idx++;
                        found = true;
                        break;
                    }
                } else if (!mismatch_used && can_finish_exact) {
                    // Mismatch case: allowed only if mismatch wasn't used yet AND
                    // the remainder word2[i+1...] can be matched with ZERO mismatches.
                    mismatch_used = true;
                    result.push_back(w1_idx);
                    w1_idx++;
                    found = true;
                    break;
                }

                w1_idx++;
            }

            if (!found) return {};
        }

        return result;
    }
};