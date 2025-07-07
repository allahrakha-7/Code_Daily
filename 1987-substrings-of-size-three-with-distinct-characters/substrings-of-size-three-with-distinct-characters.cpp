class Solution {
public:
    int countGoodSubstrings(string s) {
        // base case
        if (s.size() < 3) {
            
            return 0;
        }

        int length = 0;
        
        // hashmap to store characters
        unordered_map<char, int> Freq;

        for (int i = 0; i < 3; i++) {

            Freq[s[i]]++;
        }

        if (Freq.size() == 3) {

            length++;
        }

        for (int i = 3; i < s.size(); i++) {

            Freq[s[i - 3]]--;

            if (Freq[s[i - 3]] == 0) {

                Freq.erase(s[i - 3]);
            }

            Freq[s[i]]++;

            if (Freq.size() == 3) {

                length++;
            }
        }
        return length;
    }
};