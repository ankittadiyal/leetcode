class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            int left = i;
            int right = (i + k - 1 < n - 1) ? i + k - 1 : n - 1;
            
            while (left < right) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        
        return s;
    }
};