class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> uglyset;
        long long currentugly = 1;
        uglyset.insert(currentugly);

        for(int i = 0; i < n; ++i)
        {
            currentugly = *uglyset.begin();
            uglyset.erase(uglyset.begin());

            uglyset.insert(currentugly*2);
            uglyset.insert(currentugly*3);
            uglyset.insert(currentugly*5);
        }

        return static_cast<int<(currentugly);
    }
};