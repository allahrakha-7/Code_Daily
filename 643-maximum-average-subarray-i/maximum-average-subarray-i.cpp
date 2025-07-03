class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int windowSum = 0;

        for (int i = 0; i < k; i++) {

            windowSum += nums[i];

        }

        double maxAverage = (double) windowSum / k;

        for (int i = k; i < nums.size(); i++) {

            windowSum = windowSum - nums[i - k] + nums[i];

            double average = (double) windowSum / k;

            maxAverage = max(maxAverage, average);
    
        }
        return maxAverage;
    }
};