class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";
        sort(strs.begin(), strs.end(),[&](string& s1, string& s2)->bool{
            return s1.size() < s2.size();
        });

        int n = strs[0].size();
        for(int i = 0; i < n; ++i)
        {
            bool isSame = true;
            char c = strs[0][i];
            for(int j = 1; j < strs.size() && isSame ; ++j)
                isSame = (c == strs[j][i]); 
            
            if(isSame)
                answer.push_back(c);
            else
                break;
        }

        return answer;
    }
};