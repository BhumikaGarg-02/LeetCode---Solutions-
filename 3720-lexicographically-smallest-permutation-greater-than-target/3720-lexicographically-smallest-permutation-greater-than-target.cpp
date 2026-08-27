class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Try to find the longest common prefix match up to index i-1,
        // and place a strictly larger character at index i.
        for (int i = n - 1; i >= 0; --i) {
            // Check if we can form the prefix target[0 ... i-1]
            vector<int> freq = count;
            bool possible = true;
            for (int j = 0; j < i; ++j) {
                if (freq[target[j] - 'a'] > 0) {
                    freq[target[j] - 'a']--;
                } else {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            // Try to pick a character greater than target[i] at index i
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (freq[c] > 0) {
                    // Valid split point found! Build the result.
                    string result = target.substr(0, i);
                    result += (char)('a' + c);
                    freq[c]--;

                    // Append all remaining characters in smallest possible (sorted) order
                    for (int ch = 0; ch < 26; ++ch) {
                        while (freq[ch] > 0) {
                            result += (char)('a' + ch);
                            freq[ch]--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
    }
};