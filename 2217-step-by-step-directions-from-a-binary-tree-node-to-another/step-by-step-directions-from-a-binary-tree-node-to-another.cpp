class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> pathToStart, pathToDest;
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        // Find LCA index
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i])
            i++;

        // Steps to move up from start to LCA
        string res(pathToStart.size() - i, 'U');

        // Steps from LCA to destination
        for (int j = i; j < pathToDest.size(); j++)
            res += pathToDest[j];

        return res;
    }

private:
    bool findPath(TreeNode* root, int target, vector<char>& path) {
        if (!root) return false;
        if (root->val == target) return true;

        path.push_back('L');
        if (findPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }
};