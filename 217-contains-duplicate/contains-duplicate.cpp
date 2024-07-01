class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicateNum;

        for (int num : nums)
        {
            if (duplicateNum.find(num) != duplicateNum.end())
            {
                return true;
            }
            duplicateNum.insert(num);
        }
        return false;
    }
};