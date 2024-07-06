class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return -1;
        }
        sort(nums.begin(), nums.end());

        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != maxNum && nums[i] != minNum )
            {
                return nums[i];
            }
        }
        return -1;
    }
};