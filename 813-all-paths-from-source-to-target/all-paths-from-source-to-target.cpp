class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        dfs(graph, 0, graph.size() - 1, currentPath, allPaths);
        return allPaths;
    }

private:
    void dfs(vector<vector<int>>& graph, int node, int target,
             vector<int>& path, vector<vector<int>>& allPaths) {
        path.push_back(node);

        if (node == target) {
            allPaths.push_back(path); // store the completed path
        } else {
            for (int neighbor : graph[node])
                dfs(graph, neighbor, target, path, allPaths);
        }

        path.pop_back(); // backtrack
    }
};