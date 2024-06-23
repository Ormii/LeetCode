class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> ans, indegree(numCourses);
        queue<int> que;
        for(auto requisite : prerequisites)
        {
            graph[requisite[1]].push_back(requisite[0]);
            indegree[requisite[0]]++;
        }

        for(int i = 0; i < numCourses; ++i)
        {
            if(indegree[i] == 0)
                que.push(i);
        }

        while(!que.empty())
        {
            int course = que.front();
            que.pop();

            ans.push_back(course);

            for(auto nextcourse : graph[course])
            {
                if(--indegree[nextcourse] == 0)
                    que.push(nextcourse);
            }
        }

        if(size(ans) == numCourses)
            return true;
        
        return false;
    }
};