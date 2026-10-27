#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> createGrid(int m, int n) {
        // Initialize the m x n grid filled entirely with '#'
        std::vector<std::string> grid(m, std::string(n, '#'));
        
        // Open the first row
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        // Open the last column
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};
