class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int timePerEdge, int change) {
        // Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // times[node] will hold up to two distinct arrival times (sorted increasing)
        vector<vector<long long>> times(n + 1);

        using P = pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0LL, 1}); // start at node 1 at time 0

        while (!pq.empty()) {
            P cur = pq.top();
            pq.pop();
            long long t = cur.first;
            int u = cur.second;

            // If t is already recorded for u, skip
            bool exists = false;
            for (int i = 0; i < times[u].size(); i++) {
                if (times[u][i] == t) { exists = true; break; }
            }
            if (exists) continue;

            // If u already has two times and t is larger than the second, skip
            if (times[u].size() == 2 && t > times[u][1]) continue;

            // Record t for node u (keep at most two smallest times, sorted)
            if (times[u].size() < 2) {
                times[u].push_back(t);
                if (times[u].size() == 2 && times[u][0] > times[u][1]) {
                    long long tmp = times[u][0];
                    times[u][0] = times[u][1];
                    times[u][1] = tmp;
                }
            } else {
                // safety: replace second if this t is smaller
                if (t < times[u][1]) {
                    times[u][1] = t;
                    if (times[u][0] > times[u][1]) {
                        long long tmp = times[u][0];
                        times[u][0] = times[u][1];
                        times[u][1] = tmp;
                    }
                } else {
                    continue;
                }
            }

            // If we recorded two arrival times at destination, return the second
            if (u == n && times[u].size() == 2) {
                return (int)times[u][1];
            }

            // Compute waiting due to traffic light at node u
            long long cycles = t / change;
            long long wait = 0;
            if (cycles % 2 == 1) {
                wait = (cycles + 1) * (long long)change - t;
            }

            // Relax all neighbors
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                long long t2 = t + wait + (long long)timePerEdge;

                // Skip pushing exact duplicate times for v
                bool already = false;
                for (int j = 0; j < times[v].size(); j++) {
                    if (times[v][j] == t2) { already = true; break; }
                }
                if (already) continue;

                // Only push if v can still accept a better time (at most two kept)
                if (times[v].size() < 2) {
                    pq.push({t2, v});
                } else {
                    // If t2 is better than the current second time for v, it's promising
                    if (t2 < times[v][1]) pq.push({t2, v});
                }
            }
        }

        return -1; // problem guarantees a valid answer, but fallback
    }
};
