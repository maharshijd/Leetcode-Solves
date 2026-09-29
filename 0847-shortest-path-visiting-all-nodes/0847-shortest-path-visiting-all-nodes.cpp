class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            visited[i][mask] = true;
        }

        int steps = 0;
        int finalMask = (1 << n) - 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> curr = q.front(); q.pop();
                int node = curr.first;
                int mask = curr.second;

                if (mask == finalMask) return steps;
                for (int j = 0; j < graph[node].size(); j++) {
                    int next = graph[node][j];
                    int nextMask = mask | (1 << next);
                    if (!visited[next][nextMask]) {
                        visited[next][nextMask] = true;
                        q.push({next, nextMask});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};