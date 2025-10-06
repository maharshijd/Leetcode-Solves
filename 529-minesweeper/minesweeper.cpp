class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y);
        return board;
    }
    
private:
    void dfs(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'E') {
            return;
        }
        int mineCount = countAdjacentMines(board, x, y);
        if (mineCount > 0) {
            
            board[x][y] = '0' + mineCount;
        } else {
            board[x][y] = 'B';          
            int directions[8][2] = {
                {-1, -1}, {-1, 0}, {-1, 1},
                {0, -1},           {0, 1},
                {1, -1},  {1, 0},  {1, 1}
            };
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                dfs(board, nx, ny);
            }
        }
    }
    int countAdjacentMines(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        int count = 0;   
        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
                count++;
            }
        }
        return count;
    }
};