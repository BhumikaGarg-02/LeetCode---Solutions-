class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         vector<int> char_map(256, -1);
        int left = 0, max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            if (char_map[s[right]] >= left) {
                left = char_map[s[right]] + 1;
            }
            char_map[s[right]] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};