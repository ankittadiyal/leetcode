class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        
        // 1. Locate the position of 0 in the permutation
        int zero_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero_idx = i;
                break;
            }
        }
        
        // 2. Flags to verify if the cycle is ordered properly
        bool is_increasing = true;
        bool is_decreasing = true;
        
        // Validate the cyclic properties of the array
        for (int i = 0; i < n; ++i) {
            int next_idx = (i + 1) % n;
            
            // Check if cyclic values step strictly up modulo n
            if ((nums[i] + 1) % n != nums[next_idx]) {
                is_increasing = false;
            }
            // Check if cyclic values step strictly down modulo n
            if ((nums[i] - 1 + n) % n != nums[next_idx]) {
                is_decreasing = false;
            }
        }
        
        // If it doesn't match either orientation, it's impossible to sort
        if (!is_increasing && !is_decreasing) {
            return -1;
        }
        
        int ans = INT_MAX;
        
        // Case A: The array is a cyclically increasing permutation
        if (is_increasing) {
            // Option 1: Only left rotations
            ans = std::min(ans, zero_idx);
            // Option 2: Reverse -> Left Rotations -> Reverse
            ans = std::min(ans, n - zero_idx + 2);
        }
        
        // Case B: The array is a cyclically decreasing permutation
        if (is_decreasing) {
            // Option 3: Left Rotations -> Reverse
            ans = std::min(ans, zero_idx + 2);
            // Option 4: Reverse -> Left Rotations
            ans = std::min(ans, n - zero_idx);
        }
        
        return ans;
    }
};