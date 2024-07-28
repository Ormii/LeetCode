class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> um;
        for(auto& edge : edges)
        {
            int a = edge[0], b = edge[1];
            um[a].push_back(b);
            um[b].push_back(a);
        }

        vector<int> dist1(n+1, numeric_limits<int>::max());
        vector<int> dist2(n+1, numeric_limits<int>::max());
        vector<int> freq(n+1, 0);

        priority_queue<pair<int,int>> pq;
        pq.push({-0,1});
        dist1[1] = 0;

        while(!pq.empty())
        {
            int timetaken = -pq.top().first;
            int node = pq.top().second;
            pq.pop();

            freq[node]++;

            if(freq[node] == 2 && node == n)
                return timetaken;
            
            if((timetaken / change) % 2)
                timetaken = change * (timetaken / change + 1) + time;
            else
                timetaken = timetaken + time;


            for(auto& next : um[node])
            {
                if(freq[next] == 2)continue;

                if(dist1[next] > timetaken)
                {
                    dist2[next] = dist1[next];
                    dist1[next] = timetaken;
                    pq.push({-timetaken, next});
                }
                else if(dist2[next] > timetaken && dist1[next] != timetaken)
                {
                    dist2[next] = timetaken;
                    pq.push({-timetaken, next});
                }
            }
        }

        return 0;
    }
};