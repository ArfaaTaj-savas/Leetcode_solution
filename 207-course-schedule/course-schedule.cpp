class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int completed = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            completed++;

            for (int next : adj[course]) {
                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return completed == numCourses;
    }
};