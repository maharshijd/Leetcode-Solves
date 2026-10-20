
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x = 0, y = 0, empty = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
                if (grid[i][j] != -1)
                    empty++;
            }
        }

        return dfs(grid, x, y, empty);
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int empty) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
            return 0;

        if (grid[x][y] == 2)
            return empty == 1 ? 1 : 0;

        int temp = grid[x][y];
        grid[x][y] = -1;

        int paths = dfs(grid, x + 1, y, empty - 1)
                  + dfs(grid, x - 1, y, empty - 1)
                  + dfs(grid, x, y + 1, empty - 1)
                  + dfs(grid, x, y - 1, empty - 1);

        grid[x][y] = temp;

        return paths;
    }
};
