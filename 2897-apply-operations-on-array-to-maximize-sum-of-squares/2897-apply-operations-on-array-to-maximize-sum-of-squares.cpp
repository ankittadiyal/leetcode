class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1'000'000'007;
        const int MAX_BIT = 30;
        vector<int> bit_counts(MAX_BIT, 0);
        
        // Count the frequency of each bit position
        for (int num : nums) {
            for (int i = 0; i < MAX_BIT; ++i) {
                if ((num >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }
        
        long long ans = 0;
        // Greedily build the k largest possible numbers
        for (int step = 0; step < k; ++step) {
            long long cur = 0;
            for (int i = 0; i < MAX_BIT; ++i) {
                if (bit_counts[i] > 0) {
                    cur |= (1 << i);
                    bit_counts[i]--;
                }
            }
            ans = (ans + (cur * cur) % MOD) % MOD;
        }
        
        return ans;
    }
};