class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> same;

        for (int num : nums) {

            if (same.count(num)) {

                return true;

            }
            same.insert(num);
        }
        return false;
    }
};