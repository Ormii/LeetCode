class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxradius = 0;
        int centeridx = 0;
        int rightidx = 0;

        s = std::regex_replace(s,std::regex(""),"#");

        vector<int> radius(s.size(),0);

        for(int i = 0; i < s.size(); ++i)
        {
            if(i <= rightidx)
                radius[i] = min(radius[2*centeridx-i], rightidx - i);

            while(i - radius[i] - 1 >= 0 && i + radius[i] + 1 < s.size() && (
                s[i-radius[i]-1] == s[i+radius[i]+1]
            ))
                radius[i]++;

            if(maxradius < radius[i])
            {
                maxradius = radius[i];
                centeridx = i;
                rightidx = centeridx + radius[i];

                ans = s.substr(centeridx - radius[i], 2*radius[i] + 1);
                ans.erase(remove(ans.begin(),ans.end(),'#'),ans.end());
            }
        }

        return ans;
    }
};