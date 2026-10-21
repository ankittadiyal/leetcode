class Solution {
public:
    int minOperations(std::string s) {
        // Case 0: Already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        int n = s.length();
        // Case -1: Not sorted and length is 2 (impossible since proper substring must have length < n)
        if (n == 2) {
            return -1;
        }
        
        // Find global minimum and maximum characters
        char min_char = *std::min_element(s.begin(), s.end());
        char max_char = *std::max_element(s.begin(), s.end());
        
        // Case 1: Minimum character is already at the first index 
        // OR Maximum character is at the last index
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        // Case 2: Either the minimum or maximum character exists in the interior 
        // (anywhere from index 1 to n - 2)
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_char || s[i] == max_char) {
                return 2;
            }
        }
        
        // Case 3: Worst case (Minimum is strictly at the end AND Maximum is strictly at the start)
        return 3;
    }
};