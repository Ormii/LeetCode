class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> answer;
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int totsize = rolls.size() + n;
        int x = mean*totsize - sum;

        if(x < n || x > 6*n)
            return {};

        int distributeMean = x/n;
        int mod = x%n;
        vector<int> nElements(n, distributeMean);
        for(int i = 0; i < mod; ++i)
            nElements[i]++;

        return nElements;
    }
};