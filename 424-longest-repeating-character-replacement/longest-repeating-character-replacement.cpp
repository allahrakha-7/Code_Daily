class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        int maxLength = 0;
        int maxFreq = 0;
        
        unordered_map<char, int> charCount;

        for (int right = 0; right < s.size(); right++) {

            char character = s[right];

            charCount[character] = charCount[character] + 1;

            maxFreq = max(maxFreq, charCount[character]);

            int windowSize = right - left + 1;

            int charsToReplace = windowSize - maxFreq;

            if (charsToReplace > k) {

                char leftChar = s[left];

                charCount[leftChar] = charCount[leftChar] - 1;

                left = left + 1;
            }

            windowSize = right - left + 1;
            maxLength = max(maxLength, windowSize);
        }
        return maxLength;
    }
};