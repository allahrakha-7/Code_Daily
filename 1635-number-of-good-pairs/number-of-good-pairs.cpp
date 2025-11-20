class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int, int> umap;

        int goodpairs = 0;

        for (int num : nums) {

            goodpairs = goodpairs + umap[num];

            umap[num]++;
        }

        return goodpairs;

        
        
        // int result = 0;

        // for (int i = 0; i < nums.size(); i++) {
            
        //     for (int j = i + 1; j < nums.size(); j++) {
                
        //         if (nums[i] == nums[j] && i < j) {
                    
        //             result++;
        //         }
        //     }
        // }
        // return result;
    }
};