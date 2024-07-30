class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream ss(s);
        string Word;
        int i = 0;

        while (ss >> Word) {
            if (i >= pattern.length()) return false;
            char currentChar = pattern[i];
            if (charToWord.find(currentChar) != charToWord.end()) {
                if (charToWord[currentChar] != Word) return false;
            } else {
                charToWord[currentChar] = Word;
            }
            if (wordToChar.find(Word) != wordToChar.end()) {
                if (wordToChar[Word] != currentChar) return false;
            } else {
                wordToChar[Word] = currentChar;
            }
            i++;
        }

        return i == pattern.length();
    }
};