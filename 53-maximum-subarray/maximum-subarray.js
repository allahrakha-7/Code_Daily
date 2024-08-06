
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let maxSub = nums[0];
    let curSum = 0;

    for (let i = 0; i < nums.length; i++) {
        curSum = Math.max(nums[i], curSum + nums[i]);
        maxSub = Math.max(maxSub, curSum);
    }
    return maxSub;
};