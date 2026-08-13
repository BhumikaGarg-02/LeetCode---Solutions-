class SegmentTree {
private:
    int n;
    vector<int> maxi, pref, suff;
    vector<char> left_char, right_char;

    void pushup(int node, int l, int r) {
        int mid = l + (r - l) / 2;
        int lc = 2 * node + 1;
        int rc = 2 * node + 2;
        int left_len = mid - l + 1;
        int right_len = r - mid;

        left_char[node] = left_char[lc];
        right_char[node] = right_char[rc];

        // Default prefix and suffix lengths
        pref[node] = pref[lc];
        suff[node] = suff[rc];

        // Base max from children
        maxi[node] = max(maxi[lc], maxi[rc]);

        // Check if characters across the mid-point match
        if (right_char[lc] == left_char[rc]) {
            int merged_len = suff[lc] + pref[rc];
            maxi[node] = max(maxi[node], merged_len);

            if (pref[lc] == left_len) {
                pref[node] = left_len + pref[rc];
            }
            if (suff[rc] == right_len) {
                suff[node] = right_len + suff[lc];
            }
        }
    }

    void build(int node, int l, int r, const string& s) {
        if (l == r) {
            maxi[node] = 1;
            pref[node] = 1;
            suff[node] = 1;
            left_char[node] = s[l];
            right_char[node] = s[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid, s);
        build(2 * node + 2, mid + 1, r, s);
        pushup(node, l, r);
    }

public:
    SegmentTree(const string& s) {
        n = s.size();
        maxi.resize(4 * n);
        pref.resize(4 * n);
        suff.resize(4 * n);
        left_char.resize(4 * n);
        right_char.resize(4 * n);
        build(0, 0, n - 1, s);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            left_char[node] = ch;
            right_char[node] = ch;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node + 1, l, mid, idx, ch);
        } else {
            update(2 * node + 2, mid + 1, r, idx, ch);
        }

        pushup(node, l, r);
    }

    int getMax() {
        return maxi[0];
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        vector<int> ans;
        int k = queryCharacters.size();
        int n = s.size();

        for (int i = 0; i < k; i++) {
            st.update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getMax());
        }

        return ans;
    }
};