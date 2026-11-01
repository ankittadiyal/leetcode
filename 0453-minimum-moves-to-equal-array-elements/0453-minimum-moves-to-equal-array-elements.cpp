class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        // 1. Find the minimum element in the array
        int minElement = *std::min_element(nums.begin(), nums.end());
        
        // 2. Sum up the differences between each element and the minimum
        int moves = 0;
        for (int num : nums) {
            moves += (num - minElement);
        }
        
        return moves;
    }
};