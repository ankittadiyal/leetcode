class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Split string s into individual words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Length mismatch means they cannot match the pattern
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;

        for (int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Check if char already maps to a different word
            if (char_to_word.count(c) && char_to_word[c] != w) {
                return false;
            }
            // Check if word already maps to a different char
            if (word_to_char.count(w) && word_to_char[w] != c) {
                return false;
            }

            // Establish the bidirectional mapping
            char_to_word[c] = w;
            word_to_char[w] = c;
        }

        return true;
    }
};