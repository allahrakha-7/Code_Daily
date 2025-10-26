class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> seenNums;

        for (int num : nums) {

            if (seenNums.find(num) != seenNums.end()) {

                return true;
                
            }

            seenNums[num] = 1;

        }
        return false;
    }
};