class Solution {
private:
    bool dfs(int u, vector<vector<int>>& adj,
             vector<int>& state) {
        state[u] = 1;

        for (int v : adj[u]) {
            if (state[v] == 1) {
                return false;  // Cycle found
            }

            if (state[v] == 0 && !dfs(v, adj, state)) {
                return false;
            }
        }

        state[u] = 2;
        return true;
    }

public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (const auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);

        for (int u = 0; u < numCourses; ++u) {
            if (state[u] == 0 && !dfs(u, adj, state)) {
                return false;
            }
        }

        return true;
    }
};