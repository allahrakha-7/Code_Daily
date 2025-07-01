class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // base case
        if (nums.size() <= 1) {
            return 0;
        }

        // sorting the array
        sort(nums.begin(), nums.end());
    
        int pairs = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int sum = nums[left] + nums[right];

            if (sum < target) {

                pairs = pairs + (right - left);
            
                left++;
                
            } else {
                right--;
            }
        }
        return pairs;
    }
};