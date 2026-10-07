class Solution {
    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited = {s};
        queue<string> q;
        q.push(s);
        bool found = false;

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            
            if (isValid(cur)) {
                res.push_back(cur);
                found = true;
            }
            if (found) continue; // If valid level found, don't generate next level

            for (int i = 0; i < cur.length(); i++) {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string next_str = cur.substr(0, i) + cur.substr(i + 1);
                if (!visited.count(next_str)) {
                    visited.insert(next_str);
                    q.push(next_str);
                }
            }
        }
        return res;
    }
};