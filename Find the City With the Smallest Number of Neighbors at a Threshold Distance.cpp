class Solution {

    unordered_map<int,vector<pair<int,int>>> um;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>table(n,vector<int>(n,1'000'000));

        for(int i = 0 ; i < n; ++i)
            table[i][i] = 0;

        for(auto& edge : edges)
        {
            int a = edge[0], b = edge[1], c = edge[2];
            table[a][b] = c;
            table[b][a] = c;
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; ++j)
                    table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
        
        int answer = 0;
        int minCount = numeric_limits<int>::max();
        for(int i = 0 ;i < n; ++i)
        {
            int count = 0;
            for(int j = 0; j < n; ++j)
                if(table[i][j] <= distanceThreshold) count++;

            if(minCount >= count)
            {
                answer = i;
                minCount = count;
            }
        }

        return answer;
    }
};