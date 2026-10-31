class Solution {
private:
    int m, n;
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memo;

    int solve(int i, int j, int incomingDir, const vector<vector<int>>& grid) {
        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        if (memo[i][j][incomingDir] != -1) return memo[i][j][incomingDir];

        long long paths = 0;

        if (grid[i][j] == 1) {
            if (incomingDir == 0) {
                paths = solve(i + 1, j, 1, grid);
            } else {
                paths = solve(i, j + 1, 0, grid);
            }
        } else {
            paths = (solve(i, j + 1, 0, grid) + solve(i + 1, j, 1, grid)) % MOD;
        }

        return memo[i][j][incomingDir] = paths % MOD;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        m = grid.size();
        n = grid[0].size();
        
        memo.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        if (grid[0][0] == 1) {
            return (solve(1, 0, 1, grid) + solve(0, 1, 0, grid)) % MOD;
        }

        long long totalPaths = (solve(0, 1, 0, grid) + solve(1, 0, 1, grid)) % MOD;
        
        return totalPaths;
    }
};
