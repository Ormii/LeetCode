class Solution {
    vector<vector<int>> answer;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        recv(candidates,v,0,target);
        return answer;
    }

    void recv(vector<int>& candidates,vector<int>& v, int idx, int target)
    {
        if(target == 0)
        {
            answer.push_back(v);
            return;
        }

        for(int i = idx ; i < candidates.size() && target >= candidates[i]; ++i)
        {
            if(i == idx || candidates[i] != candidates[i-1])
            {
                v.push_back(candidates[i]);
                recv(candidates,v,i+1,target - candidates[i]);
                v.pop_back();
            }
        }
    }
};