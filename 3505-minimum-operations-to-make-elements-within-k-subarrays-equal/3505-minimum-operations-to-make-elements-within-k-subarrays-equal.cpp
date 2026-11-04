class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        vector<long long> cost(n - x + 1, 0);
        
        multiset<int> left_set, right_set;
        long long left_sum = 0, right_sum = 0;
        
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
        
        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }
        
        long long median = *left_set.rbegin();
        cost[0] = (median * left_set.size() - left_sum) + (right_sum - median * right_set.size());

        for (int i = x; i < n; ++i) {
            remove(nums[i - x]);
            add(nums[i]);
            
            median = *left_set.rbegin();
            cost[i - x + 1] = (median * left_set.size() - left_sum) + (right_sum - median * right_set.size());
        }
        
        const long long INF = 1e16;
        vector<long long> dp(k + 1, INF);
        dp[0] = 0; 

        vector<vector<long long>> history(n + 1, vector<long long>(k + 1, INF));
        history[0] = dp;
        
        for (int i = 1; i <= n; ++i) {
            vector<long long> next_dp = dp;
            
            if (i >= x) {
                int start_idx = i - x;
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
