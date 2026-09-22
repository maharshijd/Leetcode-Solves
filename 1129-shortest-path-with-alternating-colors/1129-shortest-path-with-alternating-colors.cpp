class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        for (auto e : redEdges)
            red[e[0]].push_back(e[1]);
        for (auto e : blueEdges)
            blue[e[0]].push_back(e[1]);
        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        dist[0][1] = 0;
        q.push({0, 0});
        q.push({0, 1});
        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();
            if (color == 0) {
                for (int next : blue[node]) {
                    if (dist[next][1] == -1) {
                        dist[next][1] = dist[node][0] + 1;
                        q.push({next, 1});
                    }
                }
            } else {
                for (int next : red[node]) {
                    if (dist[next][0] == -1) {
                        dist[next][0] = dist[node][1] + 1;
                        q.push({next, 0});
                    }
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1)
                ans[i] = dist[i][1];
            else if (dist[i][1] == -1)
                ans[i] = dist[i][0];
            else
                ans[i] = min(dist[i][0], dist[i][1]);
        }
        return ans;
    }
};
