class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapS[256] = {0};
        int mapT[256] = {0};
        
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }
            
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        
        return true;
    }
};