class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string shuffledStr(s.size(), ' ');

        for (int i = 0; i < s.size(); i++) {
            shuffledStr[indices[i]] = s[i];
        }
        return shuffledStr;
    }
};