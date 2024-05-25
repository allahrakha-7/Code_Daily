class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int x = nums.size(), left = 0, right = x-1;
        vector<int> res(x);

        for (int i=x-1; i>=0; i--) {
            int var;

            if (abs(nums[left]) < abs(nums[right])) {
                var = nums[right];
                right--;
            } else {
                var = nums[left];
                left++;
            }
            res[i] = var * var;
        }
        return res;
    }
};