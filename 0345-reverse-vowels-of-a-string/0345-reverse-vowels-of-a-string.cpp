class Solution {
public:
    std::string reverseVowels(std::string s) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            if (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};