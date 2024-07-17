class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> que;
        unordered_set<char> uset;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(uset.find(s[i]) != nullptr)
            {
                while(!que.empty())
                {
                    char c = que.front();
                    que.pop();
                    uset.erase(c);

                    if(c == s[i])
                        break;
                }

                uset.insert(s[i]);
                que.push(s[i]);
                continue;
            }

            uset.insert(s[i]);
            que.push(s[i]);
            ans = max(ans, (int)uset.size());
        }

        return ans;
    }
};