class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffledArray (2 * n);
        int index = 0;

        for (int i = 0; i < n; i++) {

            shuffledArray[index] = nums[i];
            shuffledArray[index + 1] = nums[n + i];
            index = index + 2;
        }
        return shuffledArray;
    }
};