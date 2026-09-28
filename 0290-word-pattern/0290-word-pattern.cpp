class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> char_to_word;
        unordered_map<string, char> word_to_char;

        for (int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];

            if (char_to_word.count(c) && char_to_word[c] != w) {
                return false;
            }
            if (word_to_char.count(w) && word_to_char[w] != c) {
                return false;
            }

            char_to_word[c] = w;
            word_to_char[w] = c;
        }

        return true;
    }
};