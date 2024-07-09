class Solution {

private:
    unordered_map<string,vector<pair<string,double>>> um;
public:

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); ++i)
        {
            auto& equation = equations[i];
            string startNode = equation[0];
            string endNode = equation[1];

            if(um.find(startNode) == um.end())
                um.insert(make_pair(startNode, vector<pair<string,double>>()));

            if(um.find(endNode) == um.end())
                um.insert(make_pair(endNode, vector<pair<string,double>>()));
            um[startNode].push_back(make_pair(endNode, values[i]));
            um[endNode].push_back(make_pair(startNode, 1.0f/values[i]));
        }

        int a = 0;
        vector<double> ans;
        for(int i = 0; i < queries.size(); ++i)
        {
            auto& query = queries[i];
            string startNode = query[0];
            string endNode = query[1];

            if(um.find(startNode) == um.end() || um.find(endNode) == um.end())
            {
                ans.push_back(-1.0f);
                continue;
            }
            
            set<string> s;
            if(DFS(startNode, endNode, s,ans, 1) == false)
            {
                ans.push_back(-1.0f);
            }
        }

        return ans;
    }

    bool DFS(string node, string findNode, set<string>& s,vector<double>& ans, double v)
    {
        if(s.find(node) != s.end())
            return false;

        if(node == findNode)
        {
            ans.push_back(round(v*100000)/100000);
            return true;
        }
            
        s.insert(node);
        bool result = false;
        vector<pair<string,double>>& edges = um[node];
        for(int i = 0; i < edges.size() && result != true; ++i)
        {
            result = DFS(edges[i].first,findNode,s,ans,v*edges[i].second);
        }
        s.erase(s.find(node));

        return result;
    }
};