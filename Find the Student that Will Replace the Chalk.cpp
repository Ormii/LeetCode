class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0LL;
        for(int i = 0; i < chalk.size(); ++i)
            sum += chalk[i];

        k %= sum;

        int answer = -1;
        for(int i = 0; i < chalk.size(); ++i)
        {
            if(k < chalk[i])
            {
                answer = i;
                break;
            }

            k -= chalk[i];
        }

        return answer; 
    }
};