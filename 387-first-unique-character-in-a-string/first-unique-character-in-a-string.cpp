class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cmap;

        for (int i = 0; i < s.size(); i++)
        {
            cmap[s[i]]++;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            if (cmap[s[i]] == 1)
            {
                return i;
                }
            }
        return -1;
    }
};