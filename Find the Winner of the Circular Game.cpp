class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i = 1; i <= n; ++i)
            v[i-1] = i;

        int index = 0;
        while(v.size() > 1)
        {
            int size = v.size();
            int m = k%size;
            m = ((m-1)+size)%size;
            index = (index + m)%size;
            auto iter = v.erase(v.begin() + index);
            index = iter - v.begin();
        }

        return v[0];
    }
};