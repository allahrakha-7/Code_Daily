class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curSum = 0;

        for (int num : nums) {
            curSum = max(num, curSum + num);
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
    }
};