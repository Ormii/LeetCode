class Solution {


public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int tmp = 1;
        do
        {
            if(tmp > n)
            {
                tmp = tmp/10 + 1;
                while(tmp%10 == 0 && tmp >= 10)
                    tmp /= 10;
            }
            else
            {
                ans.push_back(tmp);
                tmp *= 10;
            }
        }while(tmp != 1);

        return ans;     
    }
};