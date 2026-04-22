class Solution {
public:
    int dfs(unordered_map<int, Employee*>& mp, int id) {
        Employee* emp = mp[id];

        int sum = emp->importance;

        for (int sub : emp->subordinates) {
            sum += dfs(mp, sub);
        }

        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;

        for (auto e : employees) {
            mp[e->id] = e;
        }

        return dfs(mp, id);
    }
};