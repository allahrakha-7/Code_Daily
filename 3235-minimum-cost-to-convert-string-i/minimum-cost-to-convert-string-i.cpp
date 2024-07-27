class Solution {
public:
    void dijkstra(char source, unordered_map<char, vector<pair<char, int>>> &adj, vector<vector<long long>> &costMatrix) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        pq.push({0, source});
        costMatrix[source - 'a'][source - 'a'] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            char currentNode = pq.top().second;
            pq.pop();

            for (auto &it : adj[currentNode]) {
                char adjNode = it.first;
                int cost = it.second;

                if (costMatrix[source - 'a'][adjNode - 'a'] > d + cost) {
                    costMatrix[source - 'a'][adjNode - 'a'] = d + cost;
                    pq.push({d + cost, adjNode});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;

        for (int i = 0; i < original.size(); i++) {
            adj[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> costMatrix(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            dijkstra(ch, adj, costMatrix);
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == target[i]) {
                continue;
            }

            if (costMatrix[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) {
                return -1;
            }

            ans += costMatrix[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};
