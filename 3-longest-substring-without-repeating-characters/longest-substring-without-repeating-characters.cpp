class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        // unordered_map<char, int> uniqueChars;

        // int left = 0; 
        // int length = 0;

        // for (int right = 0; right < s.size(); right++) {
            
        //     if (uniqueChars.find(s[right]) != uniqueChars.end() && uniqueChars[s[right]] >= left) {

        //         left = uniqueChars[s[right]] + 1;
        //     }

        //     uniqueChars[s[right]] = right;
        //     length = max(length, right - left + 1);

        // }
        unordered_set<char> uniqueChars;

        int left = 0;
        int length = 0;

        for (int right = 0; right < s.size(); right++) {

            while (uniqueChars.find(s[right]) != uniqueChars.end()) {
                uniqueChars.erase(s[left]);
                left++;
            }

            uniqueChars.insert(s[right]);

            length = max(length, right - left + 1);
        }
        return length;
    }
};