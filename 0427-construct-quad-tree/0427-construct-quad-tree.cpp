/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool is_leaf(const vector<vector<int>>& grid, int &row, int &col, int &len) {
        for (int i = row; i < row + len; ++i) {
            for (int j = col; j < col + len; ++j) {
                if (grid[i][j] != grid[row][col]) return false;
            }
        }

        return true;
    }

    Node* DFS(const vector<vector<int>>& grid, int row, int col, int len) 
    {
        if (is_leaf(grid, row, col, len)) return new Node(grid[row][col], true);
        else 
        {
            Node* root = new Node(false, false);

            root->topLeft = DFS(grid, row, col, len / 2);
            root->topRight = DFS(grid, row, col + len / 2, len / 2);
            root->bottomRight = DFS(grid, row + len / 2, col + len / 2, len / 2);
            root->bottomLeft = DFS(grid, row + len / 2, col, len / 2);

            return root;
        }
    }

    Node* construct(const vector<vector<int>>& grid) 
    {
        return DFS(grid, 0, 0, grid.size());
    }
};