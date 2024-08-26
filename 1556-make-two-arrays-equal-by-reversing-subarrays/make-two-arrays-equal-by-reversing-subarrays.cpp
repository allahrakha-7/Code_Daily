class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() == 1 && arr.size() == 1) {
            return target[0] == arr[0];
        } else { 
            if (target.size() != arr.size()) {
                return false;
            }
        }

        vector<int> verify;

        for (int i = 0; i < arr.size(); i++) {
            verify.push_back(arr[i]);
        }

        sort(verify.begin(), verify.end());
        sort(target.begin(), target.end()); 

        return verify == target;
    }
};
