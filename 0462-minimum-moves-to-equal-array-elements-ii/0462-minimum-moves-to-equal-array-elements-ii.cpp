class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n / 2;
        
        std::nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        
        int moves = 0;
        for (int num : nums) {
            moves += std::abs(num - median);
        }
        
        return moves;
    }
};