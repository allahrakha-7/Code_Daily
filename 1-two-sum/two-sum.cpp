class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int x = target - nums[i];

            if (umap.find(x) != umap.end()) {
                if (umap[x] != i) {
                    return {umap[x], i};
                }
            }
        }
        return {};
    }
};