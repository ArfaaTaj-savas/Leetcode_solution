class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> reverseGraph(n);
        vector<int> outdegree(n, 0);

        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();

            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<int> safeNodes;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for (int prev : reverseGraph[node]) {
                outdegree[prev]--;

                if (outdegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};