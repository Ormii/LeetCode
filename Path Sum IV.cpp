class Solution {
private:
    int answer = 0;
public:
    void dfs(vector<int>& v, int idx, int accum)
    {
        if(2*idx >= v.size() && 2*idx+1 >= v.size())
        {
            answer += accum + v[idx];
            return;
        }
        else if(2*idx <= v.size() && 2*idx +1 <= v.size()
        && v[2*idx] == -1 && v[2*idx+1] == -1)
        {
            answer += accum + v[idx];
            return;
        }
    
        if(2*idx < v.size() && v[2*idx] != -1)
            dfs(v, 2*idx, accum + v[idx]);
        
        if(2*idx+1 < v.size() && v[2*idx+1] != -1)
            dfs(v, 2*idx+1, accum + v[idx]);
    }

    int pathSum(vector<int>& nums) {
        nums.insert(nums.begin(),0);

        vector<int> v(16, -1);
        for(auto& num : nums)
        {
            int level = num/100;
            int offset = (num/10)%10;
            int val = num%10;
        
            int idx = pow(2,level-1)+(offset-1);
            v[idx] = val;
        }

        dfs(v, 1, 0);

        return answer;
    }
};