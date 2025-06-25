class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> freq_map;

        for (char c : s) {
            freq_map[c]++;
        }

        for (char c : t) {
            if (freq_map.find(c) == freq_map.end() || freq_map[c] == 0) {
                return false;
            }
            freq_map[c]--;
        }
        return true;
    }
};