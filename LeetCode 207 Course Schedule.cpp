// LeetCode 207 Course Schedule.cpp

// 方法1：Kahn's Algorithm
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> outedges(numCourses, vector<int>());
        for (vector<int> &p : prerequisites) {
            indegree[p[0]]++;
            outedges[p[1]].push_back(p[0]);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (int i : outedges[front]) {
                if (--indegree[i] == 0) {
                    q.push(i);
                }
            }
            numCourses--;
        }
        return numCourses == 0;
    }
};

// 方法2：深度优先搜索
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0); // 0: unvisited, 1: visiting, 2: visited
        vector<vector<int>> inedges(numCourses, vector<int>());
        for (vector<int> &p : prerequisites) {
            inedges[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(inedges, visited, i)) {
                return false;
            }
        }
        return true;
    }
    
private:
    bool dfs(vector<vector<int>> &inedges, vector<int> &visited, int cur) {
        if (visited[cur] == 1) return false;
        if (visited[cur] == 2) return true;
        visited[cur] = 1;
        for (int i : inedges[cur]) {
            if (!dfs(inedges, visited, i)) {
                return false;
            }
        }
        visited[cur] = 2;
        return true;
    }
};