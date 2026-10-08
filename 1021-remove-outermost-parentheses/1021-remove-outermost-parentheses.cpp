class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string result = "";
        int opened = 0; 
        
        for (const char c : s) {
            if (c == '(') {
                if (++opened > 1) {
                    result += c;
                }
            } else { 
                if (--opened > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};