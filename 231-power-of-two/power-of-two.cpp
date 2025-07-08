class Solution {
public:
    bool isPowerOfTwo(int n) {
        //base case
        if (n == 1) return true;

        // check if n less than or equal to 0 and modulus of n is not equal to 0
        if (n <= 0 || n % 2 != 0) return false;

        // recursive call
        return isPowerOfTwo(n / 2);
    }
};