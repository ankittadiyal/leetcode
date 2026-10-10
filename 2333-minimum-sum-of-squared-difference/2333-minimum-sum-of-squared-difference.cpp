class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long totalDiff = 0;
        
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            totalDiff += diff[i];
        }
        
        long long k = k1 + k2;
        if (totalDiff <= k) return 0;
        
        // Count frequencies of each difference
        map<long long, long long, greater<long long>> freqMap;
        for (long long d : diff) {
            if (d > 0) freqMap[d]++;
        }
        
        // Greedily reduce the largest differences
        auto it = freqMap.begin();
        while (k > 0 && it != freqMap.end()) {
            long long currVal = it->first;
            long long count = it->second;
            
            // Look at the next smaller value (or 0 if at the end)
            auto nextIt = next(it);
            long long nextVal = (nextIt == freqMap.end()) ? 0 : nextIt->first;
            
            long long diffDrop = currVal - nextVal;
            long long operationsNeeded = diffDrop * count;
            
            if (k >= operationsNeeded) {
                k -= operationsNeeded;
                freqMap.erase(it);
                if (nextVal > 0) {
                    freqMap[nextVal] += count;
                }
                it = freqMap.begin();
            } else {
                long long reduceBy = k / count;
                long long remainder = k % count;
                
                long long newVal = currVal - reduceBy;
                freqMap.erase(it);
                freqMap[newVal] += (count - remainder);
                if (newVal - 1 >= 0) {
                    freqMap[newVal - 1] += remainder;
                }
                k = 0;
                break;
            }
        }
        
        long long ans = 0;
        for (auto& [val, count] : freqMap) {
            ans += val * val * count;
        }
        
        return ans;
    }
};
