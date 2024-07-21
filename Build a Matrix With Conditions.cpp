class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k,vector<int>(k,0));

        auto roworder = topolocialSort(k, rowConditions);
        auto colorder = topolocialSort(k, colConditions);

        if(roworder.size() < k || colorder.size() < k)
            return vector<vector<int>>();

        for(int i = 0; i < roworder.size(); ++i)
        {
            for(int j = 0; j < colorder.size(); ++j)
            {
                if(roworder[i] == colorder[j])
                {
                    ans[i][j] = roworder[i];
                    break;
                }
            }
        }

        return ans;
    }

    vector<int> topolocialSort(int k, vector<vector<int>>& conditions)
    {
        unordered_map<int,vector<int>> um;
        vector<int> indegree(k+1,0);
        for(auto& obj : conditions)
        {
            int snode = obj[0];
            int enode = obj[1];
            if(um.find(snode) == um.end())
                um.insert({snode, vector<int>()});
            if(um.find(enode) == um.end())
                um.insert({enode, vector<int>()});

            um[snode].push_back(enode);
            indegree[enode]++;
        }

        queue<int> que;
        for(int i = 1; i <= k; ++i)
            if(indegree[i] == 0)
                que.push(i);

        vector<int> result;
        while(!que.empty())
        {
            int node = que.front();
            que.pop();

            result.push_back(node);
            for(auto& enode : um[node])
            {
                indegree[enode]--;
                if(indegree[enode] == 0)
                    que.push(enode);
            }
        }

        return result;
    }
};