class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                if (ans == -1) {
                    ans = nums[i];
                } else {
                    ans &= nums[i];
                }
            }
        }
        
        // If ans remains -1, no elements were out of place (already sorted).
        return (ans == -1) ? 0 : ans;
    }
};