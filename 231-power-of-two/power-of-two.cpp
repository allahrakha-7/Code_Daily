class Solution {
public:
    // bool solve(int n, int p) {

    //     int result = pow(2, p);
        
    //     if (result == n) return true;
        
    //     if (result > n) return false;
        
    //     return solve(n, p + 1);
    // }

    bool isPowerOfTwo(int n) {
        
        return n > 0 && (n & (n - 1)) == 0;
    }
};