class Solution {
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int distance_val = 0;
        
        for (int x : arr1) {
            // Find the first element >= x - d
            auto it = std::lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // If no such element exists or the found element is > x + d, x is valid
            if (it == arr2.end() || *it > x + d) {
                distance_val++;
            }
        }
        
        return distance_val;
    }
};