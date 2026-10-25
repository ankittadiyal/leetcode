class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int closed_islands = 0;

        // Iterate through every cell in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // When land (0) is found, trigger DFS to verify if it's closed
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j, m, n)) {
                        closed_islands++;
                    }
                }
            }
        }
        return closed_islands;
    }

private:
    bool dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        // Boundary check: if out of bounds, this island touches the edge (not closed)
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        
        // Water (1) acts as a valid enclosing boundary for this branch
        if (grid[i][j] == 1) {
            return true;
        }

        // Mark the current land cell as visited by converting it to water (1)
        grid[i][j] = 1;

        // Traverse all 4 cardinal directions
        // Note: Using individual variables ensures all paths are fully traversed/visited 
        // to complete the island sinking, avoiding short-circuit evaluation errors.
        bool up = dfs(grid, i - 1, j, m, n);
        bool down = dfs(grid, i + 1, j, m, n);
        bool left = dfs(grid, i, j - 1, m, n);
        bool right = dfs(grid, i, j + 1, m, n);

        // The island is closed only if ALL directions are completely surrounded by water
        return up && down && left && right;
    }
};
