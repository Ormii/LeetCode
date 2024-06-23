class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> edgeCnt(numCourses, 0);
        queue<int> que;
        for(auto requisite : prerequisites)
        {
            graph[requisite[1]].push_back(requisite[0]);
            edgeCnt[requisite[0]]++;
        }

        for(int i = 0; i < numCourses; ++i)
        {
            if(edgeCnt[i] == 0)
                que.push(i);
        }

        while(!que.empty())
        {
            int course = que.front();
            que.pop();
            
            ans.push_back(course);

            for(auto nextcourse : graph[course])
            {
                edgeCnt[nextcourse]--;
                if(edgeCnt[nextcourse] == 0)
                    que.push(nextcourse);
            }
        }

        if(size(ans) == numCourses)
            return ans;

        return {};
    }
};