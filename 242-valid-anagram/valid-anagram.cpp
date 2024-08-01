class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> umap;
        for (char c : s) {
            umap[c]++;
        }
        for (char c : t) {
            if (umap.find(c) == umap.end() || umap[c] == 0) {
                return false;
                }
                umap[c]--;
            }
        return true;
    }
};
