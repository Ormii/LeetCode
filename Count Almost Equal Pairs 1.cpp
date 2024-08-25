class Solution {
public:
    int countPairs(vector<int>& nums) {
        vector<string> v;
        for(auto& num : nums)
        {
            string s = to_string(num);
            while(s.size() < 7)
                s.insert(s.begin(),'0');

            v.push_back(s);
        }

        int answer = 0;
        for(int i = 0; i < v.size(); ++i)
        {
            string s = v[i];
            for(int j = i+1; j < v.size(); ++j)
            {
                if(stoi(s) == stoi(v[j]))
                {
                    answer++;
                    continue;
                }
                    
                bool isAlmostEqual = false;
                for(int k = 0; k < v[j].size() && !isAlmostEqual; ++k)
                {
                    for(int l = k+1; l <v[j].size() && !isAlmostEqual; ++l)
                    {
                        swap(v[j][k],v[j][l]);
                        if(stoi(s) == stoi(v[j]))
                            isAlmostEqual = true;
                        swap(v[j][k],v[j][l]);
                    }
                }

                if(isAlmostEqual)
                {
                    answer++;
                }
            }
        }

        return answer;
    }
};