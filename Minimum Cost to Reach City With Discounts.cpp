class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        
        map<int,vector<pair<int,int>>> table;
        for(auto& highway : highways)
        {
            int a = highway[0], b = highway[1], cost = highway[2];
            table[a].push_back({b,cost});
            table[b].push_back({a,cost});
        }

        vector<vector<int>> dist(n, vector<int>(discounts+1, -1));
        vector<vector<bool>> isVisited(n, vector<bool>(discounts+1));
        priority_queue<tuple<int,int,int>> pq;

        dist[0][discounts] = 0;
        pq.push({-0,-discounts,-0});
        while(!pq.empty())
        {
            auto[cost, count, node] = pq.top();
            cost *= -1;
            count *= -1;
            node *= -1;
        
            pq.pop();

            isVisited[node][count] = true;
            for(auto& next : table[node])
            {
                int nextnode = next.first;
                int nextcost = next.second;

                if(count > 0 && !isVisited[nextnode][count - 1])
                {
                    if(dist[nextnode][count - 1] < 0 || dist[nextnode][count - 1] > dist[node][count] + nextcost/2)
                    {
                        dist[nextnode][count - 1] = dist[node][count] + nextcost/2;
                        pq.push({-dist[nextnode][count-1], -(count - 1), -nextnode}); 
                    }
                }

                if(isVisited[nextnode][count]) continue;
                if(dist[nextnode][count] < 0 || dist[nextnode][count] > dist[node][count] + nextcost)
                {
                    dist[nextnode][count] = dist[node][count] + nextcost;
                    pq.push({-dist[nextnode][count], -count, -nextnode}); 
                }
            }
        }

        int ans = numeric_limits<int>::max();
        for(int i = 0; i <= discounts; ++i)
        {
            ans = min(ans, dist[n-1][i]);
        }

        return ans;
    }
};