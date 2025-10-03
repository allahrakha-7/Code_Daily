class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int maxOnes = 0;

        int currentStreak = 0;
        
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 1) {

                currentStreak++;

                maxOnes = max(maxOnes, currentStreak);

            } else {

                currentStreak = 0;
            }
            
        }
        return maxOnes;
    }
};