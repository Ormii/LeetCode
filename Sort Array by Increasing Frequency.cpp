class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto& num : nums)
            um[num]++;

        vector<pair<int,int>> v;
        for(auto& obj : um)
            v.push_back({obj.second, obj.first});

        sort(v.begin(), v.end(), [&](pair<int,int>& obj1, pair<int,int>& obj2) -> bool{
            if(obj1.first < obj2.first)
                return true;
            else if(obj1.first == obj2.first && obj1.second > obj2.second)
                return true;

            return false;
        });

        vector<int> ans;
        for(auto& obj : v)
        {
            while(obj.first--)
                ans.push_back(obj.second);
        }

        return ans;
    }
};