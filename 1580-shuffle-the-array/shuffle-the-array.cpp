class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffledArray (2 * n);

        for (int i = 0; i < nums.size(); i++) {

            if (i % 2 == 0) {

                shuffledArray[i] = nums[i / 2];
            
            } else {

                shuffledArray[i] = nums[n + i / 2];
            }
        }
        return shuffledArray;
    }
};