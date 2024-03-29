/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return recursion(grid, 0, 0, grid.size()-1, grid.size()-1);
    }

    Node* recursion(vector<vector<int>>& grid, int top, int left, int bottom, int right){
        Node* root = new Node();
        // 递归终点: 叶子结点(区域内全部相同)
        if (checkLeaf(top, left, bottom, right, grid)){
            root->val = grid[top][left];
            root->isLeaf = true;
            return root;
        }
        // 标记当前节点
        root->isLeaf = false;
        root->val = 1;
        // 递归到均分的四个子区域
        root->topLeft = recursion(grid, top, left, top + (bottom - top) / 2, left + (right - left) / 2);
        root->topRight = recursion(grid, top, right - (right - left) / 2, top + (bottom - top) / 2, right);
        root->bottomLeft = recursion(grid, bottom - (bottom - top) / 2, left, bottom, left + (right - left) / 2);
        root->bottomRight = recursion(grid, bottom - (bottom - top) / 2, right - (right - left) / 2, bottom, right);

        return root;
    }

    // 遍历所有位置是否全部相等
    bool checkLeaf(int top, int left, int bottom, int right, vector<vector<int>>& grid){
        int same = grid[top][left];
        for (int i = top; i <= bottom; ++i){
            for (int j = left; j <= right; ++j){
                if (grid[i][j] != same) return false;
            }
        }
        return true;
    }
};
// @lc code=end

