class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       vector<pair<int, string>> nameHeightPair;

       for (size_t i = 0; i < names.size(); i++)
       {
            nameHeightPair.push_back({heights[i], names[i]});
       }

       sort(nameHeightPair.rbegin(), nameHeightPair.rend());

       vector<string> sortedPeople;
       for (size_t i = 0; i < names.size(); i++)
       {
            sortedPeople.push_back(nameHeightPair[i].second);
       }
       return sortedPeople;
    }
};