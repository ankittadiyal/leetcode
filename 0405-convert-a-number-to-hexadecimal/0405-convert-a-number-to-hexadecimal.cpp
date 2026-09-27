class Solution {
public:
    std::string toHex(int num) {
        if (num == 0) return "0";
        
        // Cast to unsigned int to naturally handle two's complement for negative numbers
        unsigned int n = num; 
        std::string chars = "0123456789abcdef";
        std::string res = "";
        
        while (n > 0) {
            res += chars[n & 0xF]; // Extract the last 4 bits
            n >>= 4;               // Logical right shift by 4 bits
        }
        
        // Reverse the string since we extracted digits from right to left
        std::reverse(res.begin(), res.end());
        return res;
    }
};