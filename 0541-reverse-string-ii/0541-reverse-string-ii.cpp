class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            // Pointers setup karein
            int left = i;
            // Agar bache hue characters k se kam hain, toh n - 1 tak hi reverse hoga
            int right = (i + k - 1 < n - 1) ? i + k - 1 : n - 1;
            
            // Khud se characters ko swap karein (bina kisi library function ke)
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