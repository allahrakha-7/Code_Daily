class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelset;

        for(char jewel : jewels) 
        {
            jewelset.insert(jewel);
        }

        int jewelCount = 0;

        for (char stone : stones) 
        {
            if (jewelset.find(stone) != jewelset.end()) 
            {
                jewelCount++;
            }
        }
        return jewelCount;
    }
};