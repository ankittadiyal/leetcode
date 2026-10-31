class Solution {
private:
    int m, n;
    int MOD = 1e9 + 7;
    // memo[i][j][dir]: dir 0 = arrived moving right (from left), dir 1 = arrived moving down (from above)
    vector<vector<vector<int>>> memo;

    int solve(int i, int j, int incomingDir, const vector<vector<int>>& grid) {
        // Out of bounds check
        if (i >= m || j >= n) return 0;

        // Base case: Reached the destination safely
        if (i == m - 1 && j == n - 1) return 1;

        // Return cached result if already calculated
        if (memo[i][j][incomingDir] != -1) return memo[i][j][incomingDir];

        long long paths = 0;

        // Determine the outgoing direction based on the current cell type
        if (grid[i][j] == 1) {
            // Mirror reflects the trajectory
            if (incomingDir == 0) {
                // Arrived by moving right -> reflected down
                paths = solve(i + 1, j, 1, grid);
            } else {
                // Arrived by moving down -> reflected right
                paths = solve(i, j + 1, 0, grid);
            }
        } else {
            // Empty cell (0): Can continue in the same direction or branch out
            paths = (solve(i, j + 1, 0, grid) + solve(i + 1, j, 1, grid)) % MOD;
        }

        return memo[i][j][incomingDir] = paths % MOD;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        m = grid.size();
        n = grid[0].size();
        
        // Initialize memoization table with -1
        memo.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        // Handle the starting cell (0, 0) directly based on its type
        if (grid[0][0] == 1) {
            // If the start is a mirror, it forces a split trajectory:
            // An imaginary rightward entry reflects down; an imaginary downward entry reflects right.
            return (solve(1, 0, 1, grid) + solve(0, 1, 0, grid)) % MOD;
        }

        // For an empty starting cell, we can freely exit right (dir 0) or exit down (dir 1)
        long long totalPaths = (solve(0, 1, 0, grid) + solve(1, 0, 1, grid)) % MOD;
        
        return totalPaths;
    }
};
