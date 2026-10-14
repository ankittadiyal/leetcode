class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        // Feasibility check: if the required sum exceeds the maximum possible 
        // sum using 'num' digits (which is num * 9), it's impossible.
        if (sum > num * 9) {
            return "";
        }
        
        std::string ans = "";
        
        // Greedily fill the string from left to right with the largest possible digits
        for (int i = 0; i < num; ++i) {
            int digit = std::min(9, sum);
            ans += std::to_string(digit);
            sum -= digit;
        }
        
        return ans;
    }
};