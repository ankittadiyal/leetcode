class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string result = "";
        int opened = 0; // Tracks the depth of open parentheses
        
        for (const char c : s) {
            if (c == '(') {
                // If depth is already 1 or more, this '(' is not the outermost one
                if (++opened > 1) {
                    result += c;
                }
            } else { // c == ')'
                // If depth is still greater than 0 after decrementing, this ')' is not the outermost one
                if (--opened > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};