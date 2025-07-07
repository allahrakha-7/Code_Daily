class Solution {
public:
    int minOperations(vector<int>& nums) {
        // base case
        if (nums.size() < 3) {
            
            for (int num : nums) {

                if (num == 0) {

                    return -1;
                }
            }
        }
        
        int operations = 0;

        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            if (nums[i] == 0) {

                operations += 1;

                nums[i] = 1 - nums[i];
                
                nums[i + 1] = 1 - nums[i + 1];

                nums[i + 2] = 1 - nums[i + 2];
                
            }
        }

        if (nums[n - 2] == 0 || nums[n - 1] == 0) {

            return -1;
        }
        return operations;
    }
};