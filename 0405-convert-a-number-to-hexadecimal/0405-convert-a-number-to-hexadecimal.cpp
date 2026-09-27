class Solution {
public:
        string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int n = num; 
        string chars = "0123456789abcdef";
        string res = "";
        
        while (n > 0) {
            res += chars[n & 0xF];
            n >>= 4;              
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};