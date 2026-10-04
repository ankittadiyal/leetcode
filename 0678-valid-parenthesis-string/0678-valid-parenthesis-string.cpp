class Solution {
public:
    bool checkValidString(std::string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;   // Treat '*' as ')'
                high++;  // Treat '*' as '('
            }

            if (high < 0) return false; // Too many ')'
            if (low < 0) low = 0;       // Reset lower bound
        }

        return low == 0;
    }
};