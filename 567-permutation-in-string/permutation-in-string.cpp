class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // base case
        if (s1.size() > s2.size()) {
            return false;
        }

        // frequency map of string s1
        unordered_map<char, int> freq;

        for (int c : s1) {
            freq[c]++;
        }

        // map for window frequency
        unordered_map<char, int> windowFreq;

        for (int i = 0; i < s2.size(); i++) {

            windowFreq[s2[i]]++;

            if (i >= s1.size()) {

                char leftChar = s2[i - s1.size()];

                windowFreq[leftChar]--;

                if (windowFreq[leftChar] == 0) {

                    windowFreq.erase(leftChar);
                }
            }

            if (windowFreq == freq) {

                return true;
            }
        }
        return false;
    }
};