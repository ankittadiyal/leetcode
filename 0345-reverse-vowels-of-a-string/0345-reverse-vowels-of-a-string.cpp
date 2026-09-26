class Solution {
public:
    std::string reverseVowels(std::string s) {
        // Use an inline helper function or a lookup string for quick O(1) checks
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer until a vowel is found
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            // Move right pointer until a vowel is found
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            
            // Swap the vowels and narrow the window
            if (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};