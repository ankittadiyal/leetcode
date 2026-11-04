class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // Step 1: Compute minimum L1 cost for each subarray of size x using sliding window median
        // cost[i] represents the cost to make nums[i...i+x-1] equal to its median
        vector<long long> cost(n - x + 1, 0);
        
        multiset<int> left_set, right_set;
        long long left_sum = 0, right_sum = 0;
        
        // Helper lambda to rebalance the dual multiset structure
        auto balance = [&]() {
            while (left_set.size() > (x + 1) / 2) {
                auto it = prev(left_set.end());
                int val = *it;
                left_sum -= val;
                left_set.erase(it);
                right_set.insert(val);
                right_sum += val;
            }
            while (left_set.size() < (x + 1) / 2 && !right_set.empty()) {
                auto it = right_set.begin();
                int val = *it;
                right_sum -= val;
                right_set.erase(it);
                left_set.insert(val);
                left_sum += val;
            }
        };
        
        // Helper lambda to add a new number to the window
        auto add = [&](int val) {
            if (left_set.empty() || val <= *left_set.rbegin()) {
                left_set.insert(val);
                left_sum += val;
            } else {
                right_set.insert(val);
                right_sum += val;
            }
            balance();
        };
        
        // Helper lambda to remove a number leaving the window
        auto remove = [&](int val) {
            auto it = left_set.find(val);
            if (it != left_set.end()) {
                left_sum -= val;
                left_set.erase(it);
            } else {
                it = right_set.find(val);
                if (it != right_set.end()) {
                    right_sum -= val;
                    right_set.erase(it);
                }
            }
            balance();
        };
        
        // Populate the initial window of size x
        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }
        
        // Minimum L1 cost is calculated relative to the median element (*left_set.rbegin())
        long long median = *left_set.rbegin();
        cost[0] = (median * left_set.size() - left_sum) + (right_sum - median * right_set.size());
        
        // Slide across the remaining elements
        for (int i = x; i < n; ++i) {
            remove(nums[i - x]);
            add(nums[i]);
            
            median = *left_set.rbegin();
            cost[i - x + 1] = (median * left_set.size() - left_sum) + (right_sum - median * right_set.size());
        }
        
        // Step 2: Dynamic Programming to select k non-overlapping windows of length x
        // dp[j] := minimum cost to select j non-overlapping subarrays using elements seen so far
        const long long INF = 1e16;
        vector<long long> dp(k + 1, INF);
        dp[0] = 0; // 0 subarrays always cost 0
        
        // To handle non-overlapping segments, keep historical DP snapshots at index (i - x)
        // history[i] stores the state of the `dp` vector right before index `i` is processed
        vector<vector<long long>> history(n + 1, vector<long long>(k + 1, INF));
        history[0] = dp;
        
        for (int i = 1; i <= n; ++i) {
            // Choice A: Skip the current element (carry forward previous state)
            vector<long long> next_dp = dp;
            
            // Choice B: Form a window of size x ending at index i-1 (which spans nums[i-x ... i-1])
            if (i >= x) {
                int start_idx = i - x;
                // Get the DP state from before this window started
                const auto& prev_state = history[start_idx];
                
                for (int j = 1; j <= k; ++j) {
                    if (prev_state[j - 1] != INF) {
                        next_dp[j] = min(next_dp[j], prev_state[j - 1] + cost[start_idx]);
                    }
                }
            }
            
            dp = next_dp;
            history[i] = dp;
        }
        
        return dp[k];
    }
};
