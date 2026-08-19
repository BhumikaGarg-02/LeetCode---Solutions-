class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            rowMask[row] |= (1 << col); // Set the bit for reserved seat
        }

        // Start assuming every row can hold 2 families
        int totalFamilies = 2 * n;

        for (const auto& [row, mask] : rowMask) {
            bool left = false, right = false, middle = false;

            // Check Left Block (Seats 2, 3, 4, 5)
            if ((mask & (1 << 2)) || (mask & (1 << 3)) || (mask & (1 << 4)) || (mask & (1 << 5))) {
                left = true;
            }
            // Check Right Block (Seats 6, 7, 8, 9)
            if ((mask & (1 << 6)) || (mask & (1 << 7)) || (mask & (1 << 8)) || (mask & (1 << 9))) {
                right = true;
            }
            // Check Middle Block (Seats 4, 5, 6, 7)
            if ((mask & (1 << 4)) || (mask & (1 << 5)) || (mask & (1 << 6)) || (mask & (1 << 7))) {
                middle = true;
            }

            if (!left && !right) {
                // Both Left and Right fit -> 2 families (no change to default max of 2)
                continue;
            } else if (!left || !right || !middle) {
                // Exactly 1 family can sit (Left, Right, or Middle)
                totalFamilies -= 1;
            } else {
                // No family can sit in this row
                totalFamilies -= 2;
            }
        }

        return totalFamilies;
    }
};