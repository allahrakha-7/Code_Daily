class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        for (int i = 0; i <= 3; i++)
        {
            minDiff = min(minDiff, nums[nums.size() - 1 - (3 - i)] - nums[i]);
        }
        return minDiff;
    }
};