class Solution {
public:
    int scoreOfParentheses(std::string s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // If it forms a base '()', add its value scaled by the depth
                if (s[i - 1] == '(') {
                    score += 1 << depth; // Equivalent to 2^depth
                }
            }
        }
        
        return score;
    }
};