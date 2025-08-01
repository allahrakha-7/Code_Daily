class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            
            int mid = left + (right - left) / 2;
            
            if (canEatAll(piles, mid, h)) {
                
                right = mid;
            } else {
                
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool canEatAll(vector<int>& piles, int k, int h) {
       
        long long hoursNeeded = 0;
        
        for (int pile : piles) {

            hoursNeeded += (pile + k - 1) / k;
            
            if (hoursNeeded > h) {

                return false;
            }
        }        
        return hoursNeeded <= h;
    }
};