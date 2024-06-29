class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;

        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
            {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty())
        {
            int r_index = radiant.front();
            int d_index = dire.front();

            radiant.pop();
            dire.pop();

            if (r_index < d_index)
            {
                radiant.push(r_index + senate.size());
            } else {
                dire.push(d_index + senate.size());
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};