class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> Graph(edges.size()+2,vector<int>());
        for(auto& edge : edges)
        {
            Graph[edge[0]].push_back(edge[1]);
            Graph[edge[1]].push_back(edge[0]);
        }

        int Center = 0;
        int MaxValue = 0;
        for(int i = 1; i < Graph.size(); ++i)
        {
            if(MaxValue < Graph[i].size())
            {
                Center = i;
                MaxValue = Graph[i].size();
            }
        }

        return Center;
    }
};