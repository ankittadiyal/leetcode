class Solution {
public:
    // Helper function placed directly inside the class
    void backtrack(vector<string>& result, string current, int openCount, int closeCount, int n) {
        // Base case: if the string is complete
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have available open brackets
        if (openCount < n) {
            backtrack(result, current + "(", openCount + 1, closeCount, n);
        }

        // Add ')' if it safely matches an open bracket
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};