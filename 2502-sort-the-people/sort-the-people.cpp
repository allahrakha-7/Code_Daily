class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        vector<pair<int, string>> peopleNames (names.size());

        for (int i = 0; i < names.size(); i++) {

            peopleNames[i] = { heights[i], names[i] };

        }

        sort(peopleNames.rbegin(), peopleNames.rend());

        vector<string> sortedNames (names.size());

        for (int i = 0; i < names.size(); i++ ) {

            sortedNames[i] = peopleNames[i].second;
        }
        return sortedNames;
    }
};