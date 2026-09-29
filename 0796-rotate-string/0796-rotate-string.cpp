class Solution {
public:
    bool rotateString(string s, string goal) {
        // If lengths are different, s can never become goal
        if (s.length() != goal.length()) {
            return false;
        }
        
        // s + s contains all possible rotations of s
        string doubled = s + s;
        
        // Check if goal is a substring of doubled
        return doubled.find(goal) != string::npos;
    }
};