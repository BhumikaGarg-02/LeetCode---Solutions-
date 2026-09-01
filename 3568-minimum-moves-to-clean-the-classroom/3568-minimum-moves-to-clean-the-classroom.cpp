class Solution {
    // maxEnergyState[r][c][mask] stores the max remaining energy seen at grid (r, c) with 'mask' litters collected
    int maxEnergyState[55][55][1 << 10];

public:
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size();
        int n = grid[0].size();

        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }

        int totalLitter = litters.size();
        int targetMask = (1 << totalLitter) - 1;

        // Initialize memoization array
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int mask = 0; mask < (1 << totalLitter); ++mask) {
                    maxEnergyState[i][j][mask] = -1;
                }
            }
        }

        // Helper to get litter index bit
        auto getLitterBit = [&](int r, int c) -> int {
            for (int k = 0; k < totalLitter; ++k) {
                if (litters[k].first == r && litters[k].second == c) {
                    return k;
                }
            }
            return -1;
        };

        // BFS queue storing {r, c, mask, energy}
        queue<tuple<int, int, int, int>> q;

        int initialMask = 0;
        int bit = getLitterBit(startX, startY);
        if (bit != -1) {
            initialMask |= (1 << bit);
        }

        int startEnergy = (grid[startX][startY] == 'R') ? energy : energy;
        q.push({startX, startY, initialMask, startEnergy});
        maxEnergyState[startX][startY][initialMask] = startEnergy;

        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, currEnergy] = q.front();
                q.pop();

                if (mask == targetMask) return moves;

                // Stop if out of energy
                if (currEnergy == 0) continue;

                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 'X') {
                        continue;
                    }

                    int nextEnergy = currEnergy - 1;
                    int nextMask = mask;

                    if (grid[nr][nc] == 'R') {
                        nextEnergy = energy; // Refill energy at 'R'
                    } else if (grid[nr][nc] == 'L') {
                        int lBit = getLitterBit(nr, nc);
                        if (lBit != -1) {
                            nextMask |= (1 << lBit);
                        }
                    }

                    // Prune states: only proceed if we reach this cell with MORE remaining energy
                    if (nextEnergy > maxEnergyState[nr][nc][nextMask]) {
                        maxEnergyState[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, nextEnergy});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};