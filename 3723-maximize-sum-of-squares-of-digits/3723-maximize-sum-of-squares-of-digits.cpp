class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) {
            return "";
        }
        
        std::string ans = "";
        
        for (int i = 0; i < num; ++i) {
            int digit = std::min(9, sum);
            ans += std::to_string(digit);
            sum -= digit;
        }
        
        return ans;
    }
};