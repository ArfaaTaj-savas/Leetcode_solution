class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            order.push_back(course);

            for (int next : adj[course]) {
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        if (order.size() == numCourses)
            return order;

        return {};
    }
};