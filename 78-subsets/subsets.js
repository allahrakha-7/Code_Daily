/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const result = [];
    const subset = [];

    const backtrack = (start) => {
        result.push([...subset]);

        for (let i = start; i < nums.length; i++) {
            subset.push(nums[i]);
            backtrack(i + 1);
            subset.pop();
        }
    };
    backtrack(0);
    return result;
};