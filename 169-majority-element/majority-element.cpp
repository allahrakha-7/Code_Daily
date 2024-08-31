class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0, maxCount = 0;

        for (int n : nums) {
            count[n] = 1 + count[n];
            res = (count[n] > maxCount) ? n : res;
            maxCount = max(count[n], maxCount);
        }
    return res;
    }
};