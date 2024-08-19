class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> memo(n+1, vector<int>(n/2+1));
        return recv(memo,n,1,0);
    }

    int recv(vector<vector<int>>& memo,int n, int i,int j)
    {
        if(i > n || j > n/2)
            return 1000;

        if(i == n)
            return 0;

        if(memo[i][j])
            return memo[i][j];

        int result = recv(memo,n,i+i,i)+2;
        if(j != 0)
            result = min(result, recv(memo,n,i+j,j)+1);
        
        memo[i][j] = result;
        return memo[i][j];
    }
};