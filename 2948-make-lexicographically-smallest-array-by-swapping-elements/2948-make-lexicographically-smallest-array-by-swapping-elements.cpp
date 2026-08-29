class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Store indices and sort them based on the values in nums
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> result(n);

        // Group into components of swap-compatible elements
        int i = 0;
        while (i < n) {
            int j = i;
            // Expand component as long as the difference between adjacent sorted values <= limit
            while (j + 1 < n && nums[indices[j + 1]] - nums[indices[j]] <= limit) {
                j++;
            }

            // Collect original indices for the current component
            vector<int> comp_indices;
            for (int k = i; k <= j; ++k) {
                comp_indices.push_back(indices[k]);
            }

            // Sort original indices to place smallest values in leftmost positions
            sort(comp_indices.begin(), comp_indices.end());

            // Assign sorted values back to the sorted positions
            for (int k = 0; k < comp_indices.size(); ++k) {
                result[comp_indices[k]] = nums[indices[i + k]];
            }

            i = j + 1; // Move to the next component
        }

        return result;
    }
};