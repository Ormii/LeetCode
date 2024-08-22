class Solution {

public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<vector<unordered_set<string>>> memo(n, vector<unordered_set<string>>(n));
        for(int i = 0; i < n; ++i)
        {
            memo[i][i].insert(string(1,word[i]));
            memo[i][i].insert("1");
        }

        for(int step = 1; step < n; ++step)
        {
            for(int i = 0; i + step < n; ++i)
            {
                int end = i + step;
                memo[i][end].insert(to_string(step+1));
                for(int split = i; split < end; ++split)
                {
                    for(auto& o : memo[i][split])
                    {
                        for(auto& other : memo[split+1][end])
                        {
                            if(isdigit(o.back()) && isdigit(other.front()))
                                continue;

                            memo[i][end].insert(o+other);
                        }
                    }
                }
            }
        }

        vector<string> answer;
        for(auto& s : memo[0][n-1])
            answer.push_back(s);

        return answer;
    }
};