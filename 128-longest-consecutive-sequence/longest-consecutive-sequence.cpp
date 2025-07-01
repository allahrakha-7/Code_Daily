class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // base case
        if (nums.empty()) return 0;

        unordered_set<int> sequence(nums.begin(), nums.end());

        int maxLength = 0;

        // traverse the array for finding distinct elements
        for (int num : sequence) {

            if (sequence.find(num - 1) == sequence.end()) {

                int currentNum = num;
                int currentLength = 1;

                while (sequence.find(currentNum + 1) != sequence.end()) {
                    currentNum++;
                    currentLength++;
                }
                maxLength = max(maxLength, currentLength);
            }
        }
        return maxLength;
    }
};