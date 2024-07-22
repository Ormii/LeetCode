class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> v;
        for(int i = 0; i < names.size(); ++i)
            v.push_back({heights[i], names[i]});
        
        sort(v.begin(), v.end(), [&](pair<int,string>& obj1, pair<int,string>& obj2)->bool{
            return obj1.first > obj2.first;
        });

        vector<string> ans;
        for(auto& obj : v)
            ans.push_back(obj.second);

        return ans;
    }
};