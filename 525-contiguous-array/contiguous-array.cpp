class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0;
        int res = 0;
        
        unordered_map<int, int> diff_index;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zero++;
            } else {
                one++;
            }
            if (diff_index.find(one - zero) == diff_index.end()) {
                diff_index[one - zero] = i;
            }
            
            if (one == zero) {
                res = one + zero;
            } else {
                int idx = diff_index[one - zero];
                res = std::max(res, i - idx);
            }
        }
        return res;
    }
};