class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int minElement = *std::min_element(nums.begin(), nums.end());
        
        int moves = 0;
        for (int num : nums) {
            moves += (num - minElement);
        }
        
        return moves;
    }
};