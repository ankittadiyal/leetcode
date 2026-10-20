class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), total_sum = 0;
        
        // Find all possible block size divisors k of n
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool valid = true;
            int prev_max = INT_MIN;
            
            // Validate sequence conditions block-by-block
            for (int i = 0; i < n && valid; i += k) {
                int c_min = INT_MAX, c_max = INT_MIN, drops = 0;
                
                for (int j = 0; j < k; ++j) {
                    int curr = nums[i + j];
                    c_min = min(c_min, curr);
                    c_max = max(c_max, curr);
                    
                    // Track structural drops including loop wrap-around
                    if (curr > nums[i + (j + 1) % k]) {
                        drops++;
                    }
                }
                
                // 1. A cyclically rotatable array block can possess at most 1 drop-off index
                // 2. The minimum element must bound the preceding block's maximum element
                if (drops > 1 || c_min < prev_max) {
                    valid = false;
                }
                prev_max = c_max;
            }
            
            if (valid) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};