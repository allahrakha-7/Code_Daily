class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        unordered_map<int, int> rowPosition, colPosition;

        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i) {
            matrix[rowPosition[i]][colPosition[i]] = i;
        }

        return matrix;
    }

private:
    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> inDegree(k + 1, 0);
        vector<vector<int>> graph(k + 1);
        queue<int> q;
        vector<int> order;

        for (const auto& condition : conditions) {
            graph[condition[0]].push_back(condition[1]);
            ++inDegree[condition[1]];
        }

        for (int i = 1; i <= k; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor : graph[node]) {
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return order.size() == k ? order : vector<int>();
    }
};