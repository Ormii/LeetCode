class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int answer = 0;
        int n = rooks.size();
        sort(rooks.begin(), rooks.end());

        for(int i = 0; i < n; ++i)
            answer += abs(i - rooks[i][0]);

        sort(rooks.begin(), rooks.end(),[&](vector<int>&v1, vector<int>&v2)->bool{
            return v1[1] < v2[1];
        });
        
        for(int i = 0; i < n; ++i)
            answer += abs(i - rooks[i][1]);

        return answer;
    }
};