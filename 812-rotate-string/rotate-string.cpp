class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()){
            return false;
        }

        for (int c : s) {
            char firstChar = s[0];
            s.erase(s.begin());
            s.push_back(firstChar);
            
            if (s == goal) {
                return true;
            }
        }
        return false;
    }
};