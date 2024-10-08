class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxProb(n,0.0f);
        maxProb[start_node] = 1.0f;

        for(int i = 0; i < n - 1; ++i)
        {
            bool hasUpdate = false;
            for(int j = 0; j < edges.size(); ++j)
            {
                int u = edges[j][0], v = edges[j][1];
                double pathProb = succProb[j];
                if(maxProb[u] * pathProb > maxProb[v])
                {
                    maxProb[v] = maxProb[u]*pathProb;
                    hasUpdate = true;
                }
                if(maxProb[v] * pathProb > maxProb[u])
                {
                    maxProb[u] = maxProb[v]*pathProb;
                    hasUpdate = true;
                }
            }

            if(!hasUpdate)
                break;
        }

        return maxProb[end_node];
    }
};