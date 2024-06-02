class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;

        for (size_t i = 0; i < s.length()-1; ++i) {
            score += abs(static_cast<int>(s[i]) - static_cast<int>(s[i+1]));
        
        }
        return score;
    }
};