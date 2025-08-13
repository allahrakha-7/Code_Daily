class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1;
        string t1;

        for (char c : s) {

            if (c == '#' && !s1.empty()) {

                s1.pop_back();

            } else if (c != '#') {

                s1.push_back(c);
                
            }
        }

        for (char c : t) {

            if (c == '#' && !t1.empty()) {

                t1.pop_back();

            } else if (c != '#') {

                t1.push_back(c);

            }
        }

        if (s1 == t1) {

            return true;
        
        } else {

            return false;

        }
    }
};