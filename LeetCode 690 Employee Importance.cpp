// LeetCode 690 Employee Importance.cpp

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee *> m;
        for (Employee *e : employees) {
            m[e->id] = e;
        }
        return dfs(m, id);
    }
    
private:
    int dfs(unordered_map<int, Employee *> &m, int id) {
        int ans = m[id]->importance;
        for (int sub : m[id]->subordinates) {
            ans += dfs(m, sub);
        }
        return ans;
    }
};