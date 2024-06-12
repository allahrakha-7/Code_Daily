class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) 
        {
            return false;
        }

        unordered_map<char, char> Charmap;
        unordered_set<char>usedChar;

        for (int i = 0; i < s.size(); i++) 
        {
            char sChar = s[i];
            char tChar = t[i];

            if (Charmap.count(sChar))
            {
                if (Charmap[sChar] != tChar)
                {
                    return false;
                }
            } else {
                if (usedChar.count(tChar))
                {
                    return false;
                }
            }
            Charmap [sChar] = tChar;
            usedChar.insert(tChar);
        }
        return true;
    }
};