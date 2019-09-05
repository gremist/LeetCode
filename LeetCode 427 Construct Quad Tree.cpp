// LeetCode 427 Construct Quad Tree.cpp

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

    Node() {}

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
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty()) return NULL;
        return dfs(grid, 0, 0, grid.size());
    }
    
private:
    Node * dfs(vector<vector<int>> &grid, int x, int y, int size) {
        if (size == 1) return new Node(grid[x][y], true, NULL, NULL, NULL, NULL);
        
        Node *tl = dfs(grid, x, y, size / 2);
        Node *tr = dfs(grid, x, y + size / 2, size / 2);
        Node *bl = dfs(grid, x + size / 2, y, size / 2);
        Node *br = dfs(grid, x + size / 2, y + size / 2, size / 2);
        
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            ((tl->val && tr->val && bl->val && br->val) ||
            !(tl->val || tr->val || bl->val || br->val))) {
            delete tl, tr, bl;
            return br;
        }
        return new Node(0, false, tl, tr, bl, br);
    }
};