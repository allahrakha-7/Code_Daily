class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int square = 0;

        for (int i = 0; i < nums.size(); i++) {
            square = nums[i] * nums[i];
            nums[i] = square;
        }
        sort (nums.begin(), nums.end());
        return nums;
    }  
};