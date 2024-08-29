class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, char> umap;

        for (auto j : jewels) {
            umap[j] = j;
        }

        int count = 0;

        for (auto st : stones) {
            if (umap.find(st) != umap.end()) {
                count++;
            }
        }
        return count;
    }
};