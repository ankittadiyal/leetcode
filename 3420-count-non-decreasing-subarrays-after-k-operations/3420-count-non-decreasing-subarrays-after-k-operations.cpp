class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        long long cost = 0;
        deque<int> dq;
        int n = nums.size();
        int j = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            long long num = nums[i];
            
            while (!dq.empty() && nums[dq.back()] < num) {
                int l = dq.back();
                dq.pop_back();
                int r = dq.empty() ? j + 1 : dq.back();
                cost += (long long)(r - l) * (num - nums[l]);
            }
            
            dq.push_back(i);

            while (cost > k) {
                cost -= (long long)nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                --j;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};