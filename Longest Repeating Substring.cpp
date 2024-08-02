class Solution {
public:
    int longestRepeatingSubstring(string s) {
        unordered_map<string,int> um;
        for(int i = 0; i < s.length(); ++i)
        {
            string key = "";
            for(int j = i; j < s.length(); ++j)
            {
                key+=s[j];
                um[key]++;
            }
        }

        int answer = 0;
        for(auto& obj : um)
        {
            if(obj.second == 1)
                continue;

            if(answer < obj.first.length())
                answer = obj.first.length();
        }

        return answer;
    }
};