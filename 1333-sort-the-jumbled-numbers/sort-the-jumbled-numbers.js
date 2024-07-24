/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function(mapping, nums) {
    const getJumbledValue = (num, mapping) => {
        if (num === 0) return mapping[0].toString();
        let jumbled = '';
        
        while (num > 0) {
            let digit = num % 10;
            jumbled = mapping[digit].toString() + jumbled;
            num = Math.floor(num / 10);
        }
        return parseInt(jumbled, 10);
    };

    let jumbledNums = nums.map(num => ({
        jumbledValue: getJumbledValue(num, mapping),
        originalNum: num
    }));

    jumbledNums.sort((a, b) => a.jumbledValue - b.jumbledValue);

    let sortedNums = jumbledNums.map(pair => pair.originalNum);

    return sortedNums;
};