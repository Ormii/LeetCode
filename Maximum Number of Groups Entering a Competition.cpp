class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());

        vector<vector<int>> v;
        int pivot = 0;
        for(int i = 1; pivot + i <= grades.size(); ++i)
        {
            vector<int> group;
            for(int j = pivot; j < pivot + i; ++j)
                group.push_back(grades[j]);
            
            v.emplace_back(group);
            pivot = pivot + i;
        }

        for(int i = pivot; i < grades.size(); ++i)
            v[v.size()-1].push_back(grades[i]);

        return v.size();
    }
};