class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;

        unordered_map<int, int> element;

        for (int num : nums) {
            element[num]++;

            if (element[num] > 1) {
                return num;
            }
        }
        return -1;
    }
};