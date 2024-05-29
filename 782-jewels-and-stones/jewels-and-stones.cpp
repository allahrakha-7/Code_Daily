class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,char> mp;

        for (auto j:jewels) {
            mp[j] = j;
        }
        int count = 0;
        for (auto st:stones) {
            if (mp.find(st) != mp.end()) {
                count++;
            }
        }
        return count;
    }
};