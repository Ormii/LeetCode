class Solution
{
public:
    const int INF = 2e9;

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        long long currentShortestDistance = runDijkstra(edges, n, source,destination);

        if(currentShortestDistance < target) return {};

        bool matchesTarget = (currentShortestDistance == target);

        for(vector<int>& edge : edges)
        {
            if(edge[2] > 0) continue;

            edge[2] = matchesTarget ? INF : 1;

            if(!matchesTarget)
            {
                long long newDistance = runDijkstra(edges, n, source, destination);
                if(newDistance <= target)
                {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return matchesTarget ? edges : vector<vector<int>>{};
    }

    long long runDijkstra(const vector<vector<int>>& edges, int nodeCount, int sourceNode, int destinationNode)
    {
        vector<vector<long long>> adjMatrix(nodeCount, vector<long long>(nodeCount, INF));

        vector<long long> minDistance(nodeCount, INF);
        vector<bool> visited(nodeCount, false);

        minDistance[sourceNode] = 0;

        for(const auto& edge : edges)
        {
            if(edge[2] != -1)
            {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0, sourceNode});

        while(!pq.empty())
        {
            auto[cost, node] = pq.top();
            pq.pop();

            visited[node] = true;

            for(int i = 0; i < nodeCount; ++i)
            {
                if(visited[i])
                    continue;
                
                if(adjMatrix[node][i] != INF)
                {
                    if(minDistance[i] == INF || minDistance[node] + adjMatrix[node][i] < minDistance[i])
                    {
                        minDistance[i] = minDistance[node] + adjMatrix[node][i];
                        pq.push({minDistance[i], i});
                    }
                }
            }
        }

        return minDistance[destinationNode];
    }
};