class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> um;
        vector<int> degree(n, 0);
        
        if(n < 2)
        {
            vector<int> centroids;
            for(int i = 0; i < n; ++i)
                centroids.push_back(i);
            return centroids;
        }

        for(auto& edge : edges)
        {
            um[edge[0]].push_back(edge[1]);
            um[edge[1]].push_back(edge[0]);

            degree[edge[0]]++;
            degree[edge[1]]++;
        }


        vector<int> leaves;
        for(auto& obj : um)
        {
            if(obj.second.size() == 1)
                leaves.push_back(obj.first);
        }

        int remain = n;
        while(remain > 2)
        {
            remain -= leaves.size();
            vector<int> newLeaves;
            for(auto& node : leaves)
            {
                for(auto& nextnode : um[node])
                {
                    if(degree[nextnode] == 1)
                        continue;
                    
                    degree[nextnode]--;
                    if(degree[nextnode] == 1)
                        newLeaves.push_back(nextnode);
                }
            }

            leaves = newLeaves;
        }

        return leaves;
    }
};