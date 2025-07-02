class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // base case
        if (nums.size() <= 1) {
            return false;
        }

        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {

            if (i > k) {
                
                seen.erase(nums[i - k - 1]);

            }
            
            if (seen.find(nums[i]) != seen.end()) {
                return true;
        
            }
        seen.insert(nums[i]);
        }
        return false;
    }
};