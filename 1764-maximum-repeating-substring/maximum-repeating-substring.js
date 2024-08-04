/**
 * @param {string} sequence
 * @param {string} word
 * @return {number}
 */
var maxRepeating = function(sequence, word) {
   const wordLength = word.length;
    let maxRepeat = 0, currentRepeat = 0, windowStart = 0;
    
    for (let i = 0; i <= sequence.length - wordLength; i++) {
        let j = i;
        while (j < sequence.length && sequence.substring(j, j + wordLength) === word) {
            currentRepeat++;
            j += wordLength;
        }
        maxRepeat = Math.max(maxRepeat, currentRepeat);
        currentRepeat = 0;
    }
    
    return maxRepeat;
};