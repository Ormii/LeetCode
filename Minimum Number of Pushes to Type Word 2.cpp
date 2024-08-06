class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> hash;
        for(auto& c : word)
            hash[c]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto& obj : hash)
            pq.push({obj.second, obj.first});

        unordered_map<char,int> um;
        int cnt = 1, press = 0;
        while(!pq.empty())
        {
            int frequence = pq.top().first;
            int c = pq.top().second;
            pq.pop();

            um[c] = cnt;
            press++;
            if(press >= 8)
            {
                cnt++;
                press = 0;
            }
        }

        int answer = 0;
        for(auto& c : word)
            answer += um[c];
        
        return answer;
    }
};