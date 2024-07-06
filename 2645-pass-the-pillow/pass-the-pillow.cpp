class Solution {
public:
    int passThePillow(int n, int time) {
        int cycleLength = (n - 1) * 2;

        int effectiveTime = time % cycleLength;

        if (effectiveTime < n)
        {
            return effectiveTime + 1;
        } else {
            return n - (effectiveTime - (n - 1));
        }
    }
};