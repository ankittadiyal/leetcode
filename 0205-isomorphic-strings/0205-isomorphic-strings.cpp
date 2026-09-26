class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Arrays to store the last seen position (+1) of each character.
        // Index represents the ASCII value of the character.
        int mapS[256] = {0};
        int mapT[256] = {0};
        
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            // If the last seen positions of the current characters do not match,
            // then the strings cannot be isomorphic.
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }
            
            // Update the positions. Storing (i + 1) to avoid conflict with the default 0 value.
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }
        
        return true;
    }
};