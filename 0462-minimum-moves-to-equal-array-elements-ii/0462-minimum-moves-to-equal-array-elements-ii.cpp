class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n / 2;
        
        // Rearranges the array so that the element at the mid index 
        // is the same as it would be in a fully sorted array.
        std::nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        
        // Calculate the total moves
        int moves = 0;
        for (int num : nums) {
            moves += std::abs(num - median);
        }
        
        return moves;
    }
};