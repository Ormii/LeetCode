class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), deg(n);
        for(auto& edge : edges)
            deg[edge[0]].push_back(edge[1]);
        
        for(int i = 0; i < n; ++i)
            Dfs(i, i, ans, deg);

        return ans;
    }

private:
    void Dfs(int node, int ancestor, vector<vector<int>>& ans, vector<vector<int>>& deg)
    {
        for(auto childnode : deg[node])
        {
            if(!ans[childnode].empty() && ans[childnode].back() == ancestor)
                continue;

            ans[childnode].push_back(ancestor);
            Dfs(childnode, ancestor, ans, deg);
        }
    }
};