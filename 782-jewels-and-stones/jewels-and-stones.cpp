class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<char> jewelSet;
        
        for (char jewel : jewels) {

            jewelSet.insert(jewel);
        }

        int count = 0;
        
        for (char stone : stones) {

            if (jewelSet.count(stone)) {

                count++;

            }
        }
        return count;
    }
};