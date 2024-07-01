class UnionFind
{
public:
    UnionFind(int n)
    {
        DistinctComponents = n;
        for(int i = 0; i < n; ++i)
            Components.push_back(i);
    }

    int FindComponents(int a)
    {
        if(Components[a] != a)
            Components[a] = FindComponents(Components[a]);
        
        return Components[a];
    }

    bool Unite(int a, int b)
    {
        if(FindComponents(a) == FindComponents(b))
            return false;

        Components[FindComponents(a)] = FindComponents(b);
        DistinctComponents--;
        return true;
    }

    bool IsUnited()
    {
        return DistinctComponents == 1;
    }

private:
    int DistinctComponents;
    vector<int> Components;
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](vector<int>&a, vector<int>&b)->bool{
            return a[0] < b[0];
        });

        UnionFind unionfind(n);

        int ans = -1;
        for(auto& log : logs)
        {
            int timestamp = log[0];
            int a = log[1];
            int b = log[2];

            unionfind.Unite(a,b);
            if(unionfind.IsUnited() == true)
            {
                ans = timestamp;
                break;
            }
        }

        return ans;
    }
};