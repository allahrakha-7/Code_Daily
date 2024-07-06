class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return -1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int key = nums[i];
            int j = i - 1;
            
            while(j >= 0 && nums[j] > key)
            {
                nums[j + 1] = nums[j];
                j--;
            }
        nums[j + 1] = key;
    }
    
    int maxNum = nums[nums.size() - 1];
    int minNum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != maxNum && nums[i] != minNum)
        {
            return nums[i];
        }
    }
        return -1;
    }
};