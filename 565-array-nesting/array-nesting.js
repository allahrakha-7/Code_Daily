/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayNesting = function(nums) {
    let maxSize = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != -1) {
            let size = 0;
            let k = i;
            
        while (nums[k] != -1) {
            let next = nums[k];
            nums[k] = -1;
            k = next;
            size++;
            }
            maxSize = Math.max(maxSize, size)
        }
    }
    return maxSize;
};