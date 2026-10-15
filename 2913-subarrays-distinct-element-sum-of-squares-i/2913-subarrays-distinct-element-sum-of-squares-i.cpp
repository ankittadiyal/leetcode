class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinct_set;
            for (int j = i; j < n; ++j) {
                distinct_set.insert(nums[j]);
                int count = distinct_set.size();
                res += count * count;
            }
        }
        
        return res;
    }
};