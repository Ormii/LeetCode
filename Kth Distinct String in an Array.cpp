class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> v;
        unordered_map<string,int> um;
        
        for(auto& str : arr)
            um[str]++;
        
        for(auto& str : arr)
        {
            if(um[str] == 1)
                v.push_back(str);
        }

        if(k-1 >= v.size())
            return "";
            
        return v[k-1];
    }
};