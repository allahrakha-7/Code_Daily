class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uSet1 (nums1.begin(), nums1.end());
        unordered_set<int> intersectedSet;

        for (int num : nums2)
        {
            if (uSet1.find(num) != uSet1.end())
            {
                intersectedSet.insert(num);
            }
        }
        return vector<int> (intersectedSet.begin(), intersectedSet.end());
    }
};