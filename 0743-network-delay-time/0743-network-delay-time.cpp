class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int inf = INT_MAX;
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, inf));
        for (int i = 1; i <= n; i++)
            graph[i][i] = 0;
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u][v] = w;
        }
        vector<int> dist(n + 1, inf);
        vector<bool> visited(n + 1, false);
        dist[k] = 0;
        for (int i = 0; i < n; i++) {
            int u = -1;
            int minDist = inf;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && dist[j] < minDist) {
                    minDist = dist[j];
                    u = j;
                }
            }
            if (u == -1)
                break;
            visited[u] = true;
            for (int v = 1; v <= n; v++) {
                if (graph[u][v] == inf)
                    continue;
                if (dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == inf)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};