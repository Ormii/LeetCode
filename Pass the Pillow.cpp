class Solution {
public:
    int passThePillow(int n, int time) {
        int mod = time % (2*(n - 1));
        return 1 + ((mod < n) ? mod : (2*(n - 1) - mod));
    }
};