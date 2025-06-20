class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int netGain = 0;
        int maxAltitude = 0;

        for (int i = 0; i < gain.size(); i++) {
            netGain = netGain + gain[i];
            gain[i] = netGain;

            if (maxAltitude < netGain) {
                maxAltitude = netGain;
            }
        }
        return maxAltitude;
    }
};