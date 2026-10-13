class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares(n);
        
        // Square all elements (use long long to prevent integer overflow)
        for (int i = 0; i < n; ++i) {
            squares[i] = static_cast<long long>(nums[i]) * nums[i];
        }
        
        // Sort the squares in ascending order
        sort(squares.begin(), squares.end());
        
        int mid = n / 2;
        long long ans = 0;
        
        // First half is subtracted, second half is added
        for (int i = 0; i < mid; ++i) {
            ans -= squares[i];
        }
        for (int i = mid; i < n; ++i) {
            ans += squares[i];
        }
        
        return ans;
    }
};