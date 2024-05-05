class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> free_server_pq;
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> run_server_pq;
        vector<int> ans(m);

        for(int i = 0; i < n ; ++i)
            free_server_pq.push({servers[i], i});
        
        int time = 0;
        for(int i = 0; i < m; ++i)
        {
            time = max(i, time);
            if(free_server_pq.empty() && run_server_pq.top().first > time)
                time = run_server_pq.top().first;

            while(!run_server_pq.empty() && run_server_pq.top().first <= time)
            {
                auto &info = run_server_pq.top();
                int server_idx = info.second;
                free_server_pq.push({servers[server_idx], server_idx});
                run_server_pq.pop();
            }

            auto& info = free_server_pq.top();
            run_server_pq.push({time + tasks[i], info.second});
            ans[i] = info.second;
            free_server_pq.pop();
        }

        return ans;
    }
};