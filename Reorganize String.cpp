using pic = pair<int,char>;

class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        priority_queue<pic, vector<pic>, less<pic>> pq;
        pic used = pair<int,char>();

        unordered_map<char,int> um;
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            char c = s[i];
            if(um.find(s[i]) == um.end())
                um.insert({s[i], 0});
            um[s[i]]++;
        }

        for(auto& obj : um)
            pq.push(make_pair(obj.second, obj.first));
        
        while(!pq.empty())
        {
            pair<int,char> obj = pq.top();
            pq.pop();

            ans += obj.second;
            obj.first--;

            if(used.first != 0)
                pq.push(used);
            
            used = obj;
        }

        if(used.first > 1)
            ans = "";
        else if(used.first == 1 && ans.back() == used.second)
            ans = "";
        
        return ans;
    }
};