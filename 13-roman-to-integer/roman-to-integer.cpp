class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int value = romanValues[s[i]];
            if (i < s.length() - 1 && value < romanValues[s[i+1]])
            {
                total -= value;
            } else {
                total += value;
            }
        }
        return total;
    }
};