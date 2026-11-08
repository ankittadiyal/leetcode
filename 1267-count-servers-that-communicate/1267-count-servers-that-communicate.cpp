class Solution {
public:
    int countServers(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<int> row_count(m, 0);
        std::vector<int> col_count(n, 0);
        
        // First pass: count servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        
        // Second pass: count communicating servers
        int communicating_servers = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1)) {
                    communicating_servers++;
                }
            }
        }
        
        return communicating_servers;
    }
};