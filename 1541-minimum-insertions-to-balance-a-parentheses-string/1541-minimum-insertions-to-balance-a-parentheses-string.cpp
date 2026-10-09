class Solution {
public:
    int minInsertions(string s) {
        int neededRight = 0; // Increment by 2 for each '('.
        int missingLeft = 0; // Increment by 1 for each missing '('.
        int missingRight = 0; // Increment by 1 for each missing ')'.

        for (const char c : s) {
            if (c == '(') {
                if (neededRight % 2 == 1) {
                    ++missingRight; // Need one ')' to complete the odd pair
                    --neededRight;  // Balance out
                }
                neededRight += 2; // Each '(' requires two ')'
            } else {
                if (--neededRight < 0) {
                    ++missingLeft; // Need a '(' for this extra ')'
                    neededRight += 2; // It provides one ')', so 1 more needed
                }
            }
        }

        return neededRight + missingLeft + missingRight;
    }
};