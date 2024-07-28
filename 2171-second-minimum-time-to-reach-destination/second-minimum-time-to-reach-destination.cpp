class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> firstTime(n + 1, INT_MAX);
        vector<int> secondTime(n + 1, INT_MAX);
        firstTime[1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [currentTime, node] = pq.top();
            pq.pop();

            for (int neighbor : adj[node]) {
                int nextTime = currentTime;

                if (currentTime / change % 2 == 1) {
                    nextTime = (currentTime / change + 1) * change;
                }
                nextTime += time;

                if (nextTime < firstTime[neighbor]) {
                    secondTime[neighbor] = firstTime[neighbor];
                    firstTime[neighbor] = nextTime;
                    pq.push({nextTime, neighbor});

                } else if (nextTime > firstTime[neighbor] && nextTime < secondTime[neighbor]) {
                    secondTime[neighbor] = nextTime;
                    pq.push({nextTime, neighbor});
                }
            }
        }
        return secondTime[n];
    }
};