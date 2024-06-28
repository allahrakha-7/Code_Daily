class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numsMap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (numsMap.find(nums[i]) != numsMap.end() && i - numsMap[nums[i]] <= k)
            {
                return true;
            }
            numsMap[nums[i]] = i;
        }
        return false;
    }
};